%% Fast Fourrier Transformation parameters
N = 3200; % 50,100,200,400,800,1600,3200,6400
nFFT = 2.56*N;

% Baseband
fmax = 800;  % frequency span (Hz)
fs = 2.56*fmax; % Nyquist frequency (Hz)

dt = 1/fs;  % sampling time (sec)
df = fmax/nFFT;  % sampling frequency (Hz)
frequency_vector = df:df:fmax;
% frequency_vector = fmax*linspace(0,1,nFFT/2+1);

T_total = nFFT*dt; % duration of the experiment (sec)
time_vector = 0:dt:T_total-dt;

%% Input signal generation with window and overlap
n_inp = 1; % number of input channels
n_out = 1; % number of output channels

hann_win_inp = zeros(nFFT,n_inp);
for i = 1:n_inp
    hann_win_inp(:,i) = hann(nFFT,'periodic');
end

hann_win_out = zeros(nFFT,n_inp);
for i = 1:n_out
    hann_win_out(:,i) = hann(nFFT,'periodic');
end

% averaging and overlap properties
n_aver = 20; % number of averaging

% overlap parameters
overlap = 50; 
r_overlap = overlap/100; % rate of overlap (%)

T_total = n_aver*T_total-(n_aver-1)*r_overlap*T_total; % total duration of input signal after windowing and averaging (sec)
total_samples = round(n_aver*nFFT-(n_aver-1)*r_overlap*nFFT); % total number of samples
total_time_vector = 0:dt:T_total-dt;

% Creating the input signal (uniformly distributed random signal)
max_inp = 1; % specify the maximum amplitude of input
min_inp = -1; % specify the maximum amplitude of input
inp = max_inp*ones(size(rand(total_samples,n_inp))) + (max_inp-min_inp)*rand(total_samples,n_inp);
y = [total_time_vector' inp];

%%
sim('MPC_implementation')

%% Output analysis
out = u(2:end,2);

I_inp_inp = zeros(nFFT,n_inp);
I_out_out = zeros(nFFT,n_out);
I_inp_out = zeros(nFFT,n_inp*n_out);
for i = 1:n_aver
    if i == 1
        istart = 1;
        iend = nFFT;
    else
        istart = (i-1)*nFFT-(i-1)*r_overlap*nFFT+1;
        iend = istart+nFFT-1;
    end
    window_inp = inp(istart:iend,:);
    window_out = out(istart:iend,:);
    
    window_inp = window_inp.*hann_win_inp;
    window_out = window_out.*hann_win_out;
    
    L = nFFT;
    
    if i == 1
        for j = 1:n_inp
            window_inp_FFT(:,j) = fft(window_inp(:,j),nFFT)/L;
            U_inp = 1/L*(hann_win_inp(:,j)'*hann_win_inp(:,j));
        end
        for j = 1:n_out
            window_out_FFT(:,j) = fft(window_out(:,j),nFFT)/L;
            U_out = 1/L*(hann_win_out(:,j)'*hann_win_out(:,j));
        end
    else
        for j = 1:n_inp
            window_inp_FFT(:,j) = fft(window_inp(:,j),nFFT)/L;
        end
        for j = 1:n_out
            window_out_FFT(:,j) = fft(window_out(:,j),nFFT)/L;
        end
    end
    
    I_inp_inp = I_inp_inp + 1/n_aver*L/U_inp*abs(window_inp_FFT).^2;
    I_out_out = I_out_out + 1/n_aver*L/U_out*abs(window_out_FFT).^2;   
    
end
inp_FFT = fft(inp(:,1),nFFT)/L;
out_FFT = fft(out(:,1),nFFT)/L;

[S_inp_out, freq_after_overlap] = cpsd(inp(:,1),out(:,1),hann_win_inp(:,1),overlap,nFFT,df);
[S_inp_inp, ~] = pwelch(inp(:,1),hann_win_inp(:,1),overlap,nFFT,df);
[S_out_out, ~] = pwelch(out(:,1),hann_win_out(:,1),overlap,nFFT,df);
H_2 = S_out_out./S_inp_out;

figure(3)
% semilogy(fmax*linspace(0,1,nFFT/2+1),(I_out_out(1:nFFT/2+1,1))./(I_inp_inp(1:nFFT/2+1,1)))
% hold on
% semilogy(freq_after_overlap*1/dt/df,abs(out_FFT(1:nFFT/2+1,1)./inp_FFT(1:nFFT/2+1,1))) 
% hold on
semilogy(freq_after_overlap*1/dt/df,abs(H_2))
xlim([0 1000])
clc
clear
close all
%%
load closed_loop_modal_analysis_0_100_hz_with_case2
sol71 = closed_loop_modal_analysis_0_10;
%%
Time = sol71.X.Data(1622:end-5829-8192);
T = Time(end)-Time(end-1);                      % Sample time
Fs = 1/T;                    % Sampling frequency
dum1 = size(Time);
L = dum1(1,2);                     % Length of signal
t = (0:L-1)*T;                % Time vector
y = sol71.Y(1,1).Data(1622:end-5829-8192)';

NFFT = 2^nextpow2(L); % Next power of 2 from length of y
Y = fft(y,NFFT)/L;
% f = Fs/2*linspace(0,1,NFFT/2+1)*2*pi;
f = Fs/2*linspace(0,1,NFFT/2+1);
sampling_time = (1-0)/(NFFT/2+1)*(Fs/2);

% Plot single-sided amplitude spectrum.
% figure;
semilogy(f,2*abs(Y(1:NFFT/2+1,:))) 
hold on
xlim([0 400])

%%
clear
clc

load closed_loop_chirp_without_disturbance_observer_st
sol71 = closed_loop_chirp_without_distu;
%%
Time = sol71.X.Data(1605:end);
T = Time(end)-Time(end-1);                      % Sample time
Fs = 1/T;                    % Sampling frequency
dum1 = size(Time);
L = dum1(1,2);                     % Length of signal
t = (0:L-1)*T;                % Time vector
y = sol71.Y(1,1).Data(1605:end)';

NFFT = 2^nextpow2(L); % Next power of 2 from length of y
Y = fft(y,NFFT)/L;
% f = Fs/2*linspace(0,1,NFFT/2+1)*2*pi;
f = Fs/2*linspace(0,1,NFFT/2+1);
sampling_time = (1-0)/(NFFT/2+1)*(Fs/2);

% Plot single-sided amplitude spectrum.
% figure;
semilogy(f,2*abs(Y(1:NFFT/2+1,:))) 
hold on
xlim([0 400])

%%
clear
clc

load closed_loop_square_without_disturbance_observer_st
sol71 = closed_loop_square_without_dist;
%%
Time = sol71.X.Data(1518:end);
T = Time(end)-Time(end-1);                      % Sample time
Fs = 1/T;                    % Sampling frequency
dum1 = size(Time);
L = dum1(1,2);                     % Length of signal
t = (0:L-1)*T;                % Time vector
y = sol71.Y(1,1).Data(1518:end)';

NFFT = 2^nextpow2(L); % Next power of 2 from length of y
Y = fft(y,NFFT)/L;
% f = Fs/2*linspace(0,1,NFFT/2+1)*2*pi;
f = Fs/2*linspace(0,1,NFFT/2+1);
sampling_time = (1-0)/(NFFT/2+1)*(Fs/2);

% Plot single-sided amplitude spectrum.
% figure;
semilogy(f,2*abs(Y(1:NFFT/2+1,:))) 
hold on
xlim([0 400])


%%

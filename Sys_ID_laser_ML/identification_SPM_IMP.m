clc
clear
close all
global dsp; if isempty(dsp), clear global dsp; dsp=1; end

%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  Specify Experiment Conditions
%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PZT sensor (y)
load('iddata.mat')

ii = 6400;
iii = 81;

iddata_shaker = shaker_2(iii:ii,3)'+shaker_2(iii:ii,4)'*1i;
freq_vec = shaker_2(iii:ii,2)*2*pi;

ny = 1;
nu = 1;
nf = ii-iii+1;
N = nf;

iddata = zeros(ny,nu,nf);

for i = 1:nf
    Y(:,1,i) = iddata_shaker(:,i);
end

n = 22;
m = nu;
p = ny;

w = real(freq_vec)';
Q = 1*eye(n); 
R = 1e-1*eye(p);   %Initial guess at covariances
T = 1/(800*2.56);

%%
z.y = Y; z.w = w;          % Specify measurements and frequencies they were obtained at
% z.T = T*0;       % Specify sample time
m.A = n;                  % Specify model order
m.type='ss';               % This is the default as well
m.w = w(:);
m.op = 's';                % Specify a continuous time model

%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  Specify Optional parts about how the estimation procedure runs
%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ms.w = w; 
Ms.nx = n; 
Ms.op = 's'; 
Ms.T = T; 

%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  Estimate on basis of noise corrupted data
%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
identified_plant_ss = fsid(z,Ms);

gt = identified_plant_ss;
W = gt.ss.A;
Hs  = gt.ss.B;
V  = gt.ss.C;

order = 12;
gt_reduced1 = reduce(ss(W,Hs,V,0),order,'ErrorType','add','Display','off','Algorithm','balance');

%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  Display the results
%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if dsp 
     data.G = Y; 
     data.w = w(:); 
     data.disp.legend = 'Data';
     data.disp.unit = 'hz';
     data.disp.colour    = 'b';
     data.disp.linestyle = '-';
     data.disp.linewidth = 0.5;
     
     gt.disp.legend = 'identified';
     gt.disp.colour    = 'r';
     gt.disp.linestyle = '-';
     gt.disp.linewidth = 0.5;

     showbode(data,gt);

end

figure;
bode(ss(W,Hs,V,0),{10*2*pi,800*2*pi})
hold on
bode(gt_reduced1,{10*2*pi,800*2*pi})

gt_reduced1_modal = canon(gt_reduced1,'modal');

W = gt_reduced1_modal.A;
Hs = gt_reduced1_modal.B;
V = gt_reduced1_modal.C;

save identified_shaker W Hs V
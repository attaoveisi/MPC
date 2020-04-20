clear 
close all
clc

%% PLANT MODEL
load identified_modal

Ap = A;
Bp = B;
Cp = C;
Hp = H;
Dp = zeros(1,2);
save plant Ap Bp Hp Cp Dp

%%
%%%%%%% Kalman Filter Design
sysk=ss(A,[Bp Hp],C,0);

[kest,L,P] = kalman(sysk,1e4,1,0);

%%%%%%% Optimal Gain
syst=ss(A,B,C,0);
[K,S,e] = lqry(syst,1e3,1e0*eye(2),0);

%%%%%%% Controller
rlqg = lqgreg(kest,K);

Ak = rlqg.A;
Bk = rlqg.B;
Ck = rlqg.C;
Dk = rlqg.D;
save controller_reduced.mat Ak Bk Ck Dk

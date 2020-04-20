clear 
close all
clc

%% PLANT MODEL
% dt = 1/400/2.56;
% dt = 5e-4;
dt = 1e-3;

load identified_modal

A_nom = A;
B_nom = B;
H_nom = H;
C_nom = C;
D_nom = zeros(1,3);
syss = ss(A,[B H],C,[0 0 0]);
syssd = c2d(syss,dt);
Ag = syssd.A;
Bg = syssd.B;
Cg = syssd.C;
Dg = syssd.D;
Hg = Bg(:,3);
Bg = Bg(:,1:2);
eig(Ag)
% step(syss,'-',syssd,'--r')

%% DOB
load identified_shaker

S_DOB = 1;
V_DOB = V;
W_DOB = W;
Cprim = [C zeros(1,size(V_DOB,2)-size(C,2))];

%% Nominal plant
%State Space Model
Am = Ag;
Bm = Bg;
Cm = Cg;

%% Augmented system (F, G, H in Eq. (18))
% Eq. (12)
[S,nnn,nnnn,nnnnn]=c2dm(W,Hs,V,0,dt);

syms alfa
char_eq = det(alfa*eye(size(S))-S);
coefs = flipud(double(coeffs(char_eq,alfa))')';
coefs = coefs(1,2:end);
ncoefs = numel(coefs);
nstate = sqrt(numel(Ag));
nout = numel(Cm)/nstate;
% first raw of F matrix (Eq. (18))
F1 = [Ag zeros(nstate,ncoefs*nout)];
% second raw of F matrix (Eq. (18))
F2 = zeros(nout,nstate+ncoefs*nout);
F2(:,1:nstate) = Cm;
for i = 1:ncoefs
    F2(:,nstate+1+(i-1)*nout:nstate+i*nout) = -coefs(1,i)*eye(nout);
end
% third raw of F matrix till end (Eq. (18))
dum1 = size(F1);
dum2 = dum1(1,2);
dum3 = dum2 - (nstate+nout);
dum4 = dum3/nout;

F3end = eye(dum4*nout);
F3end = [zeros(dum4*nout,nstate) F3end zeros(dum4*nout,nout)];
F = [F1;F2;F3end];

nin = numel(Bm)/nstate;
G = [Bm; zeros(dum2-nstate,nin)];

H = F2;

A = F;
B = G;
C = H;
eig(F)

%% DMPC Design
Np = 10;
dum5 = size(A);
% Q = blkdiag(1e0*(C_nom'*C_nom),eye(12,12));
% R = 1e0*eye(nin);

Q=1e0*(C'*C);
R = 1e1*eye(nin);

NN = zeros(dum5(1,1),nin);
%%% Test the matlab condition: Modify the weights Q and R to make [Q N;N' R] positive definite 
% eig([Q NN;NN' R])

a1=0.76; a2=0.76;
N1=5; N2=5;
lambda=0.97;
% lambda=1;
[K_lqr,P_inf,E]=dlqr(A/lambda,B/lambda,Q,R,NN);
alpha=3.1;
% alpha=1000;
Gam=lambda/alpha;
Q_bar=Gam^2*(Q-P_inf)+P_inf;
R_bar=Gam^2*R;
[omega,psi,L_m]=mpcp(A*(alpha^(-1)),B*(alpha^(-1)),[a1 a2],[N1 N2],Np,Q_bar,R_bar);
Kmpc=L_m*(omega\psi);
[eig(A) eig(A-B*Kmpc)]

%%
clc
Total_t = 20; % sec 
Total_t_sim = Total_t-10*dt;
Nsim=Total_t/dt;

% Qf = 1e-15*blkdiag(1e0*eye(6),1e0*eye(12));
% Rf = 1*1e3;
% Pf = 1e-15*blkdiag(1e0*(C_nom'*C_nom),eye(12));
% 
% % Kalman filter
% Lf = Kalman_Gain(A,C,Qf,Rf,Pf,Nsim,nout);
% % L1 = dlqr(A',C',1e-26*C'*C,1e-1)';
% [~,L2,~] = kalman(ss(A,B,C,zeros(1,2),dt),1e1,1e0,0);
% % L2 = place(A',C',[0 0.1 -0.1 0.2 -0.2 0.3 -0.3 -0.4]);


Qf=(1e-1)*eye(size(A*A'));
Qf(1:2,1:2)=(1e-1)*Qf(1:2,1:2);
Qf(3:4,3:4)=(1e1)*Qf(3:4,3:4);
Qf(5:6,5:6)=(1e1)*Qf(5:6,5:6);
Rf=(1e8)*eye(size(C*C'));
Pf=(1e15)*eye(size(A*A'));
Pf(1:2,1:2)=(1e11)*Qf(1:2,1:2);
Pf(3:4,3:4)=(1e2)*Qf(3:4,3:4);
Pf(5:6,5:6)=(1e2)*Qf(5:6,5:6);

% Kalman filter
Lf=Kalman_Gain(A,C,Qf,Rf,Pf,Nsim,nout);
L2=dlqr(A',C',1e-8*eye(size(A)),1e-7)';

[eig(A) eig(A-Lf(:,end)*C) eig(A-L2(:,1)*C)]
% [eig(A) eig(A-L2(:,1)*C)]

%% Constraints
% Nc=1;
A_cons=[L_m;-L_m];
u_max=[0.6,0.6]';
% u_max=[inf,inf]';
u_min=-[0.6,0.6]';
% u_min=-[inf,inf]';
u_bound=[u_max;-u_min];

%% Parameter Adaptor 
Ps = 1e1;
Rs = 1e-1;
% theta(:,1) = 0;

clear 
close all
clc

%% PLANT MODEL
dt=0.001;
% load Load_before
% load Load_before_luan
load identified
% A = A(1:4,1:4);
% B = B(1:4,:);
% C = C(:,1:4);
% H = H(1:4,:);

% omega_in=20;
[Ag,Bg,Cg,Dg]=c2dm(A,[B H],C,[0 0 0],dt);
Hg = Bg(:,3);
Bg = Bg(:,1:2);

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

%% DMPC Design
Np=20;
dum5 = size(A);
Q=1e1*(C'*C);
% R = 1.2e-5*eye(nin); % for square signal
% R = 5e-4*eye(nin); % for chirp
% R = 3e-4*eye(nin); % for Pulse
% R = 5e-6*eye(nin); % for sine wave second mode shape


% Second try 
% R = 5e-3*eye(nin); % for square signal
% R = 2e-1*eye(nin); % for chirp
% R = 1e-2*eye(nin); % for Pulse % case 1
R = 3e-3*eye(nin); % for Pulse % case 2

NN = zeros(dum5(1,1),nin);
%%% Test the matlab condition: Modify the weights Q and R to make [Q N;N' R] positive definite 
eig([Q NN;NN' R]);
a1=0.76; a2=0.76;
N1=5; N2=5;
lambda=0.95;
% lambda=1;
[K_lqr,P_inf,E]=dlqr(A/lambda,B/lambda,Q,R,NN);
alpha=2.1;
% alpha=1000;
Gam=lambda/alpha;
Q_bar=Gam^2*(Q-P_inf)+P_inf;
R_bar=Gam^2*R;
[omega,psi,L_m]=mpcp(A*(alpha^(-1)),B*(alpha^(-1)),[a1 a2],[N1 N2],Np,Q_bar,R_bar);
Kmpc=L_m*(omega\psi);

Total_t = 25; % sec 
Total_t_sim = Total_t-10*dt;
Nsim=Total_t/dt;
% time=0:dt:dt*(Nsim-1);
% Qf=(1e-05)*eye(size(A*A'));
% Rf=(1e-07)*eye(size(C*C'));
% Pf=(1e-02)*eye(size(A*A'));

Qf=(1e-9)*eye(size(A*A'));
Qf(3:4,3:4)=(1e3)*Qf(3:4,3:4);
Qf(5:6,5:6)=(1e5)*Qf(5:6,5:6);
Rf=(2e-2)*eye(size(C*C'));
Pf=(1e-8)*eye(size(A*A'));

% Kalman filter
Lf=Kalman_Gain(A,C,Qf,Rf,Pf,Nsim,nout);
L1=dlqr(A',C',1e-5*eye(size(A)),1e-7)';
% L2=place(A',C',[0 0.1 -0.1 0.2 -0.2 0.3 -0.3 -0.4]);

[eig(A) eig(A-B*K_lqr)]

%% Constraints
Nc=1;
A_cons=[L_m;-L_m];
u_max=[2,2]';
% u_max=[inf,inf]';
u_min=-[2,2]';
% u_min=-[inf,inf]';
u_bound=[u_max;-u_min];

%% Parameter Adaptor 
Ps = 1e1;
Rs = 1e-1;
% theta(:,1) = 0;

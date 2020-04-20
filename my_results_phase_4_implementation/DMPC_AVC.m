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
% LMI Config.
setlmis([]);

L_d = lmivar(2,[size(W_DOB,2) 1]);

%LMI terms
% lmiterm([1 1 1 0],-1);
lmiterm([1 1 2 L_d],-V_DOB'*S_DOB*V_DOB,Cprim); 
lmiterm([1 2 2 0],V_DOB'*S_DOB*V_DOB*W_DOB+W_DOB'*V_DOB'*S_DOB*V_DOB); % LMI #1: -gama^2*I


LMISYS = getlmis;

% Finding Feasible Solution 
[~,x] = feasp(LMISYS);

L_d = dec2mat(LMISYS,x,1);

%% Nominal plant
%State Space Model
Am = Ag;
Bm = Bg;
Cm = Cg;

%% Augmented system (F, G, H in Eq. (18))
% Eq. (12)
[S,~,~,~]=c2dm(W,Hs,V,0,dt);

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
Q=1e1*(C'*C); % 5e-7
% Q = 1e1*eye(size(C'*C));
R = 1e10*eye(nin);
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

Total_t = 5; % sec 
Total_t_sim = Total_t-10*dt;
Nsim=Total_t/dt;
% time=0:dt:dt*(Nsim-1);
% Qf=(1e-05)*eye(size(A*A'));
% Rf=(1e-07)*eye(size(C*C'));
% Pf=(1e-02)*eye(size(A*A'));

Qf=(1e-11)*eye(size(A*A'));
Rf=(2e-1)*eye(size(C*C'));
Pf=(1e-8)*eye(size(A*A'));

% Kalman filter
Lf=Kalman_Gain(A,C,Qf,Rf,Pf,Nsim,nout);
L1=dlqr(A',C',1e-5*eye(size(A)),1e-7)';
% L2=place(A',C',[0 0.1 -0.1 0.2 -0.2 0.3 -0.3 -0.4]);

[eig(A) eig(A-B*K_lqr)]

%% Constraints
Nc=1;
A_cons=[L_m;-L_m];
u_max=[1,1]';
% u_max=[inf,inf]';
u_min=-[1,1]';
% u_min=-[inf,inf]';
u_bound=[u_max;-u_min];

%% Parameter Adaptor 
Ps = 1e1;
Rs = 1e-1;
% theta(:,1) = 0;

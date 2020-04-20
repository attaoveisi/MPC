clear 
close all
clc
%% MEMS Gyroscope parameters (in SI units)
m=0.57e-08;
kxx=80.98;
kyy=71.62;
kxy=5;
dxx=0.429e-06;
dyy=0.687e-06;
dxy=0.0429e-06;
q0=1e-06;
w0=1e+03;
%Mass, Stiffness and Damping Matrices
M1=[m 0;0 m];
D1=[dxx 0;0 dyy];
K1=[kxx 0;0 kyy];
Kxy=[0 kxy;kxy 0];
Dxy=[0 dxy;dxy 0];
OMEGA=[0 -1;1 0]/w0;
%Nondimensinalization
D=D1/(m*w0);
K=K1/(m*w0^2);

%% PLANT MODEL
dt=0.001;
omega_in=20;
Ag1=[zeros(2,2) eye(2);-(K+0.2*K+(Kxy/(m*w0^2))) -D-0.1*D-(Dxy/(m*w0))-2*OMEGA*(omega_in)];
Bg1=[zeros(2,2);eye(2)];
Cg1=[eye(2) zeros(2,2)];
[Ag,Bg,Cg,Dg]=c2dm(Ag1,Bg1,Cg1,[0 0;0 0],dt);

%% Reference signal 
w1=1.191931942010938e+002;
%w1=7;
x0=0.1;
%State Space Model
A_con=[zeros(2,2) eye(2);-K -D];
B_con=[zeros(2,2);eye(2)];
Cm=[1 0 0 0;0 1 0 0];

%% Discretization
Am=eye(4)+A_con*dt+0.5*(A_con*dt)^2;
Bm=B_con*dt+(1/2)*A_con*B_con*dt^2;
o4=zeros(4,2);
A=[Am o4 o4;Cm*Am 2*eye(2) -(1+(w1*dt)^2)*eye(2);o4' eye(2) zeros(2,2)];
B=[Bm;Cm*Bm;zeros(2,2)];
C=[zeros(2,4) eye(2) zeros(2,2)];
%A=[Am o4 o4;Cm 2*eye(2) -(1+(w1*dt)^2)*eye(2);o4' eye(2) zeros(2,2)];
%B=[Bm;zeros(2,2);zeros(2,2)];
%C=[Cm 2*eye(2) -(1+(w1*dt)^2)*eye(2)];
%% DMPC Design
Np=60;
Q=C'*C;
R=0.001*eye(2);
a1=0.5; a2=0.5;
N1=5; N2=5;
lambda=0.90;
[K_lqr,P_inf,E]=dlqr(A/lambda,B/lambda,Q,R);
alpha=2.1;
Gam=lambda/alpha;
Q_bar=Gam^2*(Q-P_inf)+P_inf;
R_bar=Gam^2*R;
[omega,psi,L_m]=mpcp(A*(alpha^(-1)),B*(alpha^(-1)),[a1 a2],[N1 N2],Np,Q_bar,R_bar);
Kmpc=L_m*(omega\psi);
%L_ob=dlqr(A',C',100*eye(size(A)),0.01*eye(2))';
Nsim=5000;
time=0:dt:dt*(Nsim-1);
xm(:,1)=[0.01 0.01 0.0 0]';
y(:,1)=[0.01 0.01]';
X(:,1)=[0 0 0 0 0 0 0 0];
Qf=(1e-06)*eye(8);
Rf=(1e-03)*eye(2);
Pf=(1e+02)*eye(8);
% Kalman filter
Lf=Kalman_Gain(A,C,Qf,Rf,Pf,Nsim);
% Thermal noise 
Tnoise=1*[10;1]*rand(1,Nsim)*(1e-03);
% Measurement noise
Msnoise=1*[1 1]'*randn(1,Nsim)*1e-05;

%% Parameter Adaptor 
Ps=[1e+03 0;0 1e+03];
Rs=1e-03;
theta(:,1)=[0 0.5*(Kxy(1,2)/(m*w0^2))]';

%% Generating the reference trajectory
for i1=1:Nsim
    r(:,i1)=x0*[sin(w1*(i1-1)*dt) 0]';
end

%% Constraints
Nc=1;
A_cons=[L_m;-L_m];
u_max=[1.7e+04,0.25e+04]'/26;
%u_max=[inf,inf]';
u_min=-[1.7e+04,0.25e+04]'/26;
%u_min=-[inf,inf]';
u_bound=[u_max;-u_min];

%L1=dlqr(A',C',10*eye(size(A)),0.001*eye(2))';
%% Simulations
% jj=1;
% for kk=1:Nsim
%     if kk==1
%         b_cons=u_bound;
%     us(:,kk)=L_m*QPhild(omega,psi*X(:,kk),A_cons,b_cons);
%     u(:,kk)=us(:,kk);
%     xm(:,kk+1)=xm(:,kk)+dt*(Ag1*xm(:,kk)+Bg1*(u(:,kk)+Tnoise(:,kk)));
%     y(:,kk+1)=Cg*xm(:,kk+1)+Msnoise(:,kk);
%     X(:,kk+1)=A*X(:,kk)+B*us(:,kk)+Lf(:,2*kk-1:2*kk)*(y(:,kk)-r(:,kk)-C*X(:,kk));
%     % Parameter Adaptation
%         Phi=[x0*w1*cos(w1*(kk-1)*dt) x0*sin(w1*(kk-1)*dt)]';
%     elseif kk==2
%      b_cons=u_bound-2*[u(:,kk-1);-u(:,kk-1)];
%     us(:,kk)=L_m*QPhild(omega,psi*X(:,kk),A_cons,b_cons);
%     u(:,kk)=us(:,kk)+2*u(:,kk-1);
%     xm(:,kk+1)=xm(:,kk)+dt*(Ag1*xm(:,kk)+Bg1*(u(:,kk)+Tnoise(:,kk)));
%     y(:,kk+1)=Cg*xm(:,kk+1)+Msnoise(:,kk);
%     X(:,kk+1)=A*X(:,kk)+B*us(:,kk)+Lf(:,2*kk-1:2*kk)*(y(:,kk)-r(:,kk)-C*X(:,kk));
%     % Parameter Adaptation
%      Phi=[x0*w1*cos(w1*(kk-1)*dt) x0*sin(w1*(kk-1)*dt)]';
%     else
%      b_cons=u_bound-2*[u(:,kk-1);-u(:,kk-1)]+(1+(w1*dt)^2)*[u(:,kk-2);-u(:,kk-2)];
%     us(:,kk)=L_m*QPhild(omega,psi*X(:,kk),A_cons,b_cons);
%     u(:,kk)=us(:,kk)+2*u(:,kk-1)-(1+(w1*dt)^2)*u(:,kk-2);
%     xm(:,kk+1)=xm(:,kk)+dt*(Ag1*xm(:,kk)+Bg1*(u(:,kk)+Tnoise(:,kk)));
%     y(:,kk+1)=Cg*xm(:,kk+1)+Msnoise(:,kk);
%     X(:,kk+1)=A*X(:,kk)+B*us(:,kk)+Lf(:,2*kk-1:2*kk)*(y(:,kk)-r(:,kk)-C*X(:,kk));
%     % Parameter Adaptation
%     Phi=[x0*w1*cos(w1*(kk-1)*dt) x0*sin(w1*(kk-1)*dt)]';
%     if kk>500
%     Ks=Ps*(Phi/(Phi'*Ps*Phi+Rs));
%     theta(:,jj+1)=theta(:,jj)+Ks*(u(2,kk)-Phi'*theta(:,jj));
%     Ps=(eye(2)-Ks*Phi')*Ps*(eye(2)-Ks*Phi')'+Ks*Rs*Ks';
%     jj=jj+1;
%     end
%     end
% end
% 
% %% Results
% ttime=0:dt:dt*(size(theta,2)-1);
% figure(1)
% subplot(2,1,1)
% plot(time,y(1,1:Nsim),time,r(1,:),'--')
% legend('x','xr')
% xlim([0,2.0])
% ylabel('$x\ position(\mu m)$','interpreter','latex','fontsize',14)
% subplot(2,1,2)
% plot(time,y(1,1:Nsim)-r(1,:))
% xlim([0,2.0])
% xlabel('$Time(ms)$','interpreter','latex','fontsize',14)
% ylabel('$Tracking\ error(\mu m)$','interpreter','latex','fontsize',14)
% 
% figure(2)
% plot(time,y(2,1:Nsim))
% ylabel('$y\ position(\mu m)$','interpreter','latex','fontsize',14)
% xlabel('$Time(ms)$','interpreter','latex','fontsize',14)
% xlim([0,2.0])
% 
% figure(3)
% subplot(2,1,1)
% plot(time,u(1,1:Nsim)*(m*q0*w0^2)*1e+06)
% xlim([0,2])
% hold on
% plot(time,u_bound(1)*ones(1,size(u,2))*(m*q0*w0^2)*1e+06,'--',time,-u_bound(1)*ones(1,size(u,2))*(m*q0*w0^2)*1e+06,'--')
% xlim([0,2])
% ylabel('$u_x(N)$','interpreter','latex','fontsize',14)
% subplot(2,1,2)
% plot(time,u(2,1:Nsim)*(m*q0*w0^2)*1e+06)
% xlim([0,2])
% hold on
% plot(time,u_bound(2)*ones(1,size(u,2))*(m*q0*w0^2)*1e+06,'--',time,-u_bound(2)*ones(1,size(u,2))*(m*q0*w0^2)*1e+06,'--')
% xlim([0,2])
% ylabel('$u_y(N)$','interpreter','latex','fontsize',14)
% xlabel('$Time(ms)$','interpreter','latex','fontsize',14)
% 
% figure(4)
% subplot(2,1,1)
% plot(ttime,(w0*(theta(1,:))/2)+88.02+0.85,ttime,(omega_in)*ones(size(theta(1,:))),'red')
% xlim([0,4.5])
% ylim([0,40])
% ylabel('$\Omega_z(rad/s)$','interpreter','latex','fontsize',14)
% subplot(2,1,2)
% plot(ttime,(m*w0^2)*theta(2,:),ttime,(kxy)*ones(size(theta(1,:))),'red')
% xlim([0,4.5])
% ylim([0,6])
% xlabel('$Time(ms)$','interpreter','latex','fontsize',14)
% ylabel('$k_{xy}(N/m)$','interpreter','latex','fontsize',14)
% 

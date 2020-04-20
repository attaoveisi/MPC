function [K]=Kalman_Gain(A,C,Q,Rf,Pf,Nsim,nout) % (A,C,Qf,Rf,Pf,Nsim);
%%Offline compution of Kalman gains 
I=eye(size(A,1));
for kk=2:Nsim
P_=A*Pf*A'+Q;    
K(:,nout*kk-1)=P_*C'/(C*P_*C'+Rf);
Pf=(I-K(:,nout*kk-1)*C)*P_*(I-K(:,nout*kk-1)*C)'+K(:,nout*kk-1)*Rf*K(:,nout*kk-1)';
end
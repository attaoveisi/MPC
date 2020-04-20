function [K]=Kalman_Gain(a,c,Q,R,P,nsim)
%%Offline compution of Kalman gains 
I=eye(size(a,1));
for kk=1:nsim
P_=a*P*a'+Q;    
K(:,2*kk-1:2*kk)=P_*c'/(c*P_*c'+R);
P=(I-K(:,2*kk-1:2*kk)*c)*P_*(I-K(:,2*kk-1:2*kk)*c)'+K(:,2*kk-1:2*kk)*R*K(:,2*kk-1:2*kk)';
end
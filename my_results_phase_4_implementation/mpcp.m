%% This function generates the Omega and Psi matrices for MIMO systems
%The cost function J=ethe'*OMEGA*ethe+2*etha'*PSI*x(k)
%GAMMA matrix is for calculating Kmpc
function [OMEGA,PSI,GAMMA]=mpcp(A,B,a,N,Np,Q,R)
%State vector dimension
n=size(A,1);
%Number of outputs
m=size(B,2);
S=zeros(n,sum(N));
p=zeros(sum(N),sum(N));
q=zeros(sum(N),n);
GAMMA=zeros(m,sum(N));
RL=zeros(sum(N),sum(N));
RL(1:N(1),1:N(1))=R(1,1)*eye(N(1));
for i=1:size(N,2)-1
    RL(1+N(i):N(i)+N(i+1),1+N(i):N(i)+N(i+1))=R(i+1,i+1)*eye(N(1+i));
end
for j=1:Np
    no=1;
for i=1:m
    [Al,Lo]=lagd(a(i),N(i));
    Sc1=B(:,i)*Lo';
    S(:,no:no+N(i)-1)=convsum(A,Sc1,Al,j);
    GAMMA(i,no:no+N(i)-1)=Lo';
    no=no+N(i);
end
PHI_M=S';
    p=p+PHI_M*Q*PHI_M';
    q=q+PHI_M*Q*(A^j);
end
OMEGA=p+RL;
PSI=q;

    
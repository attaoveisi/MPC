%This function computes the "CONVOLUTION SUM" that appears in DLQR based cost
%function
function [S] = convsum(A,Sc1,Al,m)
if m==1
    S=Sc1;
else
    S=Sc1;
    for i=2:m
    S=A*S+Sc1*((Al^(i-1))');
    end
end


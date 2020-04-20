clc
clear
close all

%%
load iddata
dt = 2.5e-4;
tf = 50;
win = 0:dt:tf;
win_shaker = 0:dt:40-dt-dt;

dum1 = size(win,2);
dums_1 = dum1 - size(win_shaker,2);
signal = zeros(3,dum1*3);
totalt = 0:dt:tf*3+(3-1)*dt;

f0 = 1;
f1 = 100;
y = chirp(win,f0,tf,f1,'linear');
signal(1,1:dum1) = y;
signal(2,dum1+1:2*dum1) = y;
signal(3,2*dum1+1:3*dum1) = y;

exp_time = iddata.X.Data;
exp_out = iddata.Y(1,1).Data;
exp_act1 = iddata.Y(1,2).Data;

for i = 1:size(exp_act1,2)
    
    if (exp_act1(1,i) == 0)
        if (exp_act1(1,i+1) == 0)
            if (exp_act1(1,i+2) == 0)
                dum2 = i-1;
                break
            end
        end
    end
end
num_jumped_iter = dum1-dum2;
signal = signal(:,num_jumped_iter+1:end-dums_1);
totalt = totalt(:,num_jumped_iter+1:end-dums_1)-totalt(:,num_jumped_iter+1);
%%%% !!!! 2 steps are take out from shaker time window

plot(exp_time)
hold on
plot(totalt)
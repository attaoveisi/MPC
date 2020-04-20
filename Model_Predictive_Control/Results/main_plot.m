close all
clc
clear

load open_loop
load closed_loop_mpc
load closed_loop_mpcdrc
load closed_loop_pid

load open_loop_step
load closed_loop_step_mpc
load closed_loop_step_mpcdrc
load closed_loop_step_pid
%%
set(gcf,'PaperPositionMode','auto')
print('Fig5','-dtiff','-r1200')

%%
figure(1)
plot(open_loop.X.Data,open_loop.Y(1,6).Data*125)
hold on
plot(closed_loop_pid.X.Data,closed_loop_pid.Y(1,6).Data*125)
hold on
plot(closed_loop_mpc.X.Data,closed_loop_mpc.Y(1,6).Data*125)
hold on
plot(closed_loop_mpcdrc.X.Data,closed_loop_mpcdrc.Y(1,6).Data*125)
legend('open loop','closed-loop: PID','closed-loop: MPC','closed-loop: MPC/DRC')
xlabel('time (s)')
ylabel('velocity (mm/s)')

%%
figure(2)
subplot(3,1,1)
plot(closed_loop_pid.X.Data,closed_loop_pid.Y(1,2).Data)
hold on
plot(closed_loop_pid.X.Data,closed_loop_pid.Y(1,1).Data)
xlabel('time (s)')
ylabel('control signal (V)')
legend('actuator 2: PID','actuator 1: PID')

subplot(3,1,2)
plot(closed_loop_mpc.X.Data,closed_loop_mpc.Y(1,2).Data)
hold on
plot(closed_loop_mpc.X.Data,closed_loop_mpc.Y(1,1).Data)
xlabel('time (s)')
ylabel('control signal (V)')
legend('actuator 2: MPC','actuator 1: MPC')

subplot(3,1,3)
plot(closed_loop_mpcdrc.X.Data,closed_loop_mpcdrc.Y(1,2).Data)
hold on
plot(closed_loop_mpcdrc.X.Data,closed_loop_mpcdrc.Y(1,1).Data)
legend('actuator 2: MPC/DRC','actuator 1: MPC/DRC')
xlabel('time (s)')
ylabel('control signal (V)')

%%
figure(3)
plot(closed_loop_mpc.X.Data,closed_loop_mpc.Y(1,3).Data*125)
hold on
plot(closed_loop_mpcdrc.X.Data,closed_loop_mpcdrc.Y(1,3).Data*125)
legend('closed-loop: MPC','closed-loop: MPC/DRC')
xlabel('time (s)')
ylabel('output estimation error (mm/s)')

%%
figure(4)
plot(open_loop_step.X.Data,open_loop_step.Y(1,6).Data*125)
hold on
plot(closed_loop_step_pid.X.Data,closed_loop_step_pid.Y(1,6).Data*125)
hold on
plot(closed_loop_step_mpc.X.Data,closed_loop_step_mpc.Y(1,6).Data*125)
hold on
plot(closed_loop_step_mpcdrc.X.Data,closed_loop_step_mpcdrc.Y(1,6).Data*125)
legend('open loop','closed-loop: PID','closed-loop: MPC','closed-loop: MPC/DRC')
xlabel('time (s)')
ylabel('velocity (mm/s)')

%%
figure(5)
subplot(2,1,1)
plot(closed_loop_step_pid.X.Data,closed_loop_step_pid.Y(1,2).Data)
hold on
plot(closed_loop_step_pid.X.Data,closed_loop_step_pid.Y(1,1).Data)
xlabel('time (s)')
ylabel('control signal (V)')
legend('actuator 2: PID','actuator 1: PID')

subplot(2,1,2)
plot(closed_loop_step_mpc.X.Data,closed_loop_step_mpc.Y(1,2).Data)
hold on
plot(closed_loop_step_mpc.X.Data,closed_loop_step_mpc.Y(1,1).Data)
xlabel('time (s)')
ylabel('control signal (V)')
legend('actuator 2: MPC','actuator 1: MPC')

% subplot(2,1,3)
% plot(closed_loop_step_mpcdrc.X.Data,closed_loop_step_mpcdrc.Y(1,2).Data)
% hold on
% plot(closed_loop_step_mpcdrc.X.Data,closed_loop_step_mpcdrc.Y(1,1).Data)
% legend('actuator 2: MPC/DRC','actuator 1: MPC/DRC')
% xlabel('time (s)')
% ylabel('control signal (V)')

%%
figure(6)
plot(closed_loop_step_mpc.X.Data,closed_loop_step_mpc.Y(1,3).Data*125)
hold on
plot(closed_loop_step_mpcdrc.X.Data,closed_loop_step_mpcdrc.Y(1,3).Data*125)
legend('closed-loop: MPC','closed-loop: MPC/DRC')
xlabel('time (s)')
ylabel('output estimation error (mm/s)')

%%
load FRF

figure(7)

subplot(2,1,1)
plot(open_loop(:,2),10*log10(abs(open_loop(:,3)+open_loop(:,4)*1i)))
hold on
plot(PID(:,2),10*log10(abs(PID(:,3)+PID(:,4)*1i)))
hold on
plot(MPC(:,2),10*log10(abs(MPC(:,3)+MPC(:,4)*1i)))
hold on
plot(MPCDRC(:,2),10*log10(abs(MPCDRC(:,3)+MPCDRC(:,4)*1i)))
xlabel('frequency (Hz)')
ylabel('FRF (N/(mm/s))')

subplot(2,1,2)
plot(open_loop(:,2),(180/pi)*(angle(open_loop(:,3)+open_loop(:,4)*1i)))
hold on
plot(PID(:,2),(180/pi)*(angle(PID(:,3)+PID(:,4)*1i)))
hold on
plot(MPC(:,2),(180/pi)*(angle(MPC(:,3)+MPC(:,4)*1i)))
hold on
plot(MPCDRC(:,2),(180/pi)*(angle(MPCDRC(:,3)+MPCDRC(:,4)*1i)))
legend('open loop','closed-loop: PID','closed-loop: MPC','closed-loop: MPC/DRC')
xlabel('frequency (Hz)')
ylabel('phase (°)')

%%
figure(8)
plot(open_loop_coherence(:,2),open_loop_coherence(:,3))
hold on
plot(PID_coherence(:,2),PID_coherence(:,3))
hold on
plot(MPC_coherence(:,2),MPC_coherence(:,3))
hold on
plot(MPCDRC_coherence(:,2),MPCDRC_coherence(:,3))
legend('open loop','closed-loop: PID','closed-loop: MPC','closed-loop: MPC/DRC')
xlabel('frequency (Hz)')
ylabel('coherence function')
ylim([0 1.2])

%%
clear
load open_loop_saturated
load closed_loop_saturated_lqg
load closed_loop_saturated_mpc
load closed_loop_saturated_mpcdrc

figure(9)
plot(open_loop_saturated.X.Data,open_loop_saturated.Y(1,6).Data*125)
hold on
plot(closed_loop_saturated_lqg.X.Data,closed_loop_saturated_lqg.Y(1,6).Data*125)
hold on
plot(closed_loop_saturated_mpc.X.Data,closed_loop_saturated_mpc.Y(1,6).Data*125)
hold on
plot(closed_loop_saturated_mpcdrc.X.Data,closed_loop_saturated_mpcdrc.Y(1,6).Data*125)
legend('open loop','closed-loop: LQG','closed-loop: MPC','closed-loop: MPC/DRC')
xlabel('time (s)')
ylabel('velocity (mm/s)')

%%
figure(10)
subplot(3,1,1)
plot(closed_loop_saturated_lqg.X.Data,closed_loop_saturated_lqg.Y(1,2).Data)
hold on
plot(closed_loop_saturated_lqg.X.Data,closed_loop_saturated_lqg.Y(1,1).Data)
xlabel('time (s)')
ylabel('control signal (V)')
legend('actuator 2: LQG','actuator 1: LQG')
ylim([-220 220])

subplot(3,1,2)
plot(closed_loop_saturated_mpc.X.Data,closed_loop_saturated_mpc.Y(1,2).Data)
hold on
plot(closed_loop_saturated_mpc.X.Data,closed_loop_saturated_mpc.Y(1,1).Data)
xlabel('time (s)')
ylabel('control signal (V)')
legend('actuator 2: MPC','actuator 1: MPC')
ylim([-220 220])

subplot(3,1,3)
plot(closed_loop_saturated_mpcdrc.X.Data,closed_loop_saturated_mpcdrc.Y(1,2).Data)
hold on
plot(closed_loop_saturated_mpcdrc.X.Data,closed_loop_saturated_mpcdrc.Y(1,1).Data)
legend('actuator 2: MPC/DRC','actuator 1: MPC/DRC')
xlabel('time (s)')
ylabel('control signal (V)')
ylim([-220 220])
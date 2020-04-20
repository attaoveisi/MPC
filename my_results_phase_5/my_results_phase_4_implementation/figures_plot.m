clc
clear
close all

% font size
a = 11;

%%
load open_loop_square_st
load closed_loop_square_without_disturbance_observer_st
load closed_loop_square_with_disturbance_observer015_st
load square_comparison

time1 = open_loop_square_st.X.Data-0.099;
output1 = open_loop_square_st.Y(1,7).Data*125;

% Closed-loop:MPC
closed_loop_square_without_disturbance_observer_st = closed_loop_square_without_dist;
time2 = closed_loop_square_without_disturbance_observer_st.X.Data-0.976;
u1_1 = closed_loop_square_without_disturbance_observer_st.Y(1,1).Data;
u2_1 = closed_loop_square_without_disturbance_observer_st.Y(1,2).Data;
output_estimated1 = closed_loop_square_without_disturbance_observer_st.Y(1,3).Data*125;
output_estimated2 = closed_loop_square_without_disturbance_observer_st.Y(1,4).Data*125;
disturbance = closed_loop_square_without_disturbance_observer_st.Y(1,5).Data;
disturbance_observed = closed_loop_square_without_disturbance_observer_st.Y(1,6).Data;
output2 = closed_loop_square_without_disturbance_observer_st.Y(1,7).Data*125;

% Closed-loop:MPC DRC
closed_loop_square_with_disturbance_observer015_st = closed_loop_square_with_disturb;
time2_1 = closed_loop_square_with_disturbance_observer015_st.X.Data-0.918;
u1_1_1 = closed_loop_square_with_disturbance_observer015_st.Y(1,1).Data;
u2_1_1 = closed_loop_square_with_disturbance_observer015_st.Y(1,2).Data;
output_estimated1_1 = closed_loop_square_with_disturbance_observer015_st.Y(1,3).Data*125;
output_estimated2_1 = closed_loop_square_with_disturbance_observer015_st.Y(1,4).Data*125;
output2_1 = closed_loop_square_with_disturbance_observer015_st.Y(1,7).Data*125;

% Closed-loop: PID
time3 = square_comparison.X.Data-0.439;
output3 = square_comparison.Y(1,4).Data*125;
u1_2 = square_comparison.Y(1,1).Data;
u2_2 = square_comparison.Y(1,2).Data;


% Create figure
figure1 = figure;

% Create axes
axes1 = axes('Parent',figure1,'FontSize',a);

box(axes1,'on');
hold(axes1,'on');

plot(time1,output1,'DisplayName','open loop',...
    'Color',[0.831372559070587 0.815686285495758 0.7843137383461]);
hold on
plot(time2,output2,'DisplayName','closed-loop: MPC',...
    'Color',[0 0.447058826684952 0.74117648601532]);
hold on
% plot(time2_1,output2_1,'DisplayName','closed-loop: MPC/DRC',...
%     'Color',[0 1 1]);
% hold on 
plot(time3,output3,'DisplayName','closed-loop: PID',...
    'Color',[0.850980401039124 0.325490206480026 0.0980392172932625]);
xlabel('time (sec)')
ylabel('measured velocity (mm/sec)')
legend1 = legend(axes1,'show');
set(legend1,'FontSize',a);
xlim([0 6.25])


figure2 = figure;

% Create axes
axes2 = axes('Parent',figure2,'FontSize',a);

box(axes2,'on');
hold(axes2,'on');

estimted_error = output_estimated1-output_estimated2;
plot(time2,estimted_error)
xlabel('time (sec)')
ylabel('output estimation error (mm/sec)')
xlim([0 6.25])

% Create figure
figure3 = figure;

subplot1 = subplot(2,1,1,'Parent',figure3,'FontSize',a);

% Create axes
box(subplot1,'on');
hold(subplot1,'on');

plot(time2,u2_1,'DisplayName','actuator 1: MPC',...
    'Color',[0 0.447058826684952 0.74117648601532],'Parent',subplot1);
hold on
plot(time2,u1_1,'DisplayName','actuator 2: MPC',...
    'Color',[0.850980401039124 0.325490206480026 0.0980392172932625],'Parent',subplot1);
xlabel('time (sec)')
ylabel('applied control effort (V)')
xlim([0 6.25])

subplot2 = subplot(2,1,2,'Parent',figure3,'FontSize',a);
box(subplot2,'on');
hold(subplot2,'on');

plot(time3,u2_2,'DisplayName','actuator 1: PID',...
    'Color',[0 0.447058826684952 0.74117648601532],'Parent',subplot2);
hold on
plot(time3,u1_2,'DisplayName','actuator 2: PID',...
    'Color',[0.850980401039124 0.325490206480026 0.0980392172932625],'Parent',subplot2);
xlabel('time (sec)')
ylabel('applied control effort (V)')
xlim([0 6.25])

%% CHIRP SIGNAL
load open_loop_chirp_st
load closed_loop_chirp_without_disturbance_observer_st
load closed_loop_chirp_with_disturbance_observer015_st

time4 = open_loop_chirp_st.X.Data;
output4 = open_loop_chirp_st.Y(1,7).Data*125;

% Closed-loop :MPC
closed_loop_chirp_without_disturbance_observer_st = closed_loop_chirp_without_distu;
time5 = closed_loop_chirp_without_disturbance_observer_st.X.Data-0.962;
u1_3 = closed_loop_chirp_without_disturbance_observer_st.Y(1,1).Data;
u2_3 = closed_loop_chirp_without_disturbance_observer_st.Y(1,2).Data;
output_estimated1 = closed_loop_chirp_without_disturbance_observer_st.Y(1,3).Data*125;
output_estimated2 = closed_loop_chirp_without_disturbance_observer_st.Y(1,4).Data*125;
disturbance = closed_loop_chirp_without_disturbance_observer_st.Y(1,5).Data;
disturbance_observed = closed_loop_chirp_without_disturbance_observer_st.Y(1,6).Data;
output5 = closed_loop_chirp_without_disturbance_observer_st.Y(1,7).Data*125;

% Closed-loop:MPC/DRC
closed_loop_chirp_with_disturbance_observer015_st = closed_loop_chirp_with_disturba;
time6 = closed_loop_chirp_with_disturbance_observer015_st.X.Data-0.953;
u1_4 = closed_loop_chirp_with_disturbance_observer015_st.Y(1,1).Data;
u2_4 = closed_loop_chirp_with_disturbance_observer015_st.Y(1,2).Data;
output_estimated1_1 = closed_loop_chirp_with_disturbance_observer015_st.Y(1,3).Data*125;
output_estimated2_1 = closed_loop_chirp_with_disturbance_observer015_st.Y(1,4).Data*125;
output6 = closed_loop_chirp_with_disturbance_observer015_st.Y(1,7).Data*125;

% Create figure
figure4 = figure;

% Create axes
axes4 = axes('Parent',figure4,'FontSize',a);

box(axes4,'on');
hold(axes4,'on');

plot(time4,output4,'DisplayName','open loop',...
    'Color',[0.831372559070587 0.815686285495758 0.7843137383461]);
hold on
plot(time6,output6,'DisplayName','closed-loop: MPC',...
    'Color',[0 0.447058826684952 0.74117648601532]);
hold on
plot(time5,output5,'DisplayName','closed-loop: MPC&DRC',...
    'Color',[0.850980401039124 0.325490206480026 0.0980392172932625]);
xlabel('time (sec)')
ylabel('measured velocity (mm/sec)')
legend4 = legend(axes4,'show');
set(legend4,'FontSize',a);
xlim([0 8.83])

figure5 = figure;

% Create axes
axes5 = axes('Parent',figure5,'FontSize',a);

box(axes5,'on');
hold(axes5,'on');

estimted_error1 = output_estimated1-output_estimated2;
estimted_error2 = output_estimated1_1-output_estimated2_1;
plot(time6,estimted_error2,'DisplayName','closed-loop: MPC',...
    'Color',[0 0.447058826684952 0.74117648601532])
hold on
plot(time5,estimted_error1,'DisplayName','closed-loop: MPC/DRC',...
    'Color',[0.850980401039124 0.325490206480026 0.0980392172932625])

xlabel('time (sec)')
ylabel('output estimation error (mm/sec)')
legend5 = legend(axes5,'show');
set(legend5,'FontSize',a);
xlim([0 8.83])


% Create figure
figure6 = figure;

subplot1 = subplot(2,1,1,'Parent',figure6,'FontSize',a);

% Create axes
box(subplot1,'on');
hold(subplot1,'on');

plot(time5,u2_3,'DisplayName','actuator 1: MPC',...
    'Color',[0 0.447058826684952 0.74117648601532],'Parent',subplot1);
hold on
plot(time5,u1_3,'DisplayName','actuator 2: MPC',...
    'Color',[0.850980401039124 0.325490206480026 0.0980392172932625],'Parent',subplot1);
xlabel('time (sec)')
ylabel('applied control effort (V)')
xlim([0 8.83])

subplot2 = subplot(2,1,2,'Parent',figure6,'FontSize',a);
box(subplot2,'on');
hold(subplot2,'on');

plot(time6,u2_4,'DisplayName','actuator 1: MPC/DRC',...
    'Color',[0 0.447058826684952 0.74117648601532],'Parent',subplot2);
hold on
plot(time6,u1_4,'DisplayName','actuator 2: MPC/DRC',...
    'Color',[0.850980401039124 0.325490206480026 0.0980392172932625],'Parent',subplot2);
xlabel('time (sec)')
ylabel('applied control effort (V)')
xlim([0 8.83])


figure7 = figure;

% Create axes
axes7 = axes('Parent',figure7,'FontSize',a);

box(axes7,'on');
hold(axes7,'on');

estimted_error = disturbance_observed-disturbance;
plot(time5,estimted_error)
xlabel('time (sec)')
ylabel('disturbance estimation error')
xlim([0 8.83])

%% Modal Analysis
load Frequency_domain

figure;
subplot(2,1,1)
semilogy(modal_open_loop(:,2),abs(modal_open_loop(:,3)+1i*modal_open_loop(:,4)))
hold on
semilogy(modal_closed_loop_MPC(:,2),abs(modal_closed_loop_MPC(:,3)+1i*modal_closed_loop_MPC(:,4)))
hold on
semilogy(modal_closed_loop_MPCDRC(:,2),abs(modal_closed_loop_MPCDRC(:,3)+1i*modal_closed_loop_MPCDRC(:,4)))
hold on
semilogy(modal_closed_loop_PID(:,2),abs(modal_closed_loop_PID(:,3)+1i*modal_closed_loop_PID(:,4)))
xlabel('frequency (Hz)')
ylabel('FRF (N/(m/s^2))')

ylim([0.8 1000])

subplot(2,1,2)
plot(modal_open_loop(:,2),abs(180/pi*angle(modal_open_loop(:,3)+1i*modal_open_loop(:,4))))
hold on
plot(modal_closed_loop_MPC(:,2),abs(180/pi*angle(modal_closed_loop_MPC(:,3)+1i*modal_closed_loop_MPC(:,4))))
hold on
plot(modal_closed_loop_MPCDRC(:,2),abs(180/pi*angle(modal_closed_loop_MPCDRC(:,3)+1i*modal_closed_loop_MPCDRC(:,4))))
hold on
plot(modal_closed_loop_PID(:,2),abs(180/pi*angle(modal_closed_loop_PID(:,3)+1i*modal_closed_loop_PID(:,4))))
legend('open loop','closed-loop: MPC','closed-loop: MPC/DRC','closed-loop: PID')
xlabel('frequency (Hz)')
s = sprintf('(%c)', char(176));
ylabel(['phase ',num2str(s)])
ylim([-5 185])


figure;
plot(modal_open_loop_coherence(:,2),modal_open_loop_coherence(:,3))
hold on
plot(modal_closed_loop_MPC_coherence(:,2),modal_closed_loop_MPC_coherence(:,3))
hold on
plot(modal_closed_loop_MPCDRC_coherence(:,2),modal_closed_loop_MPCDRC_coherence(:,3))
hold on
plot(modal_closed_loop_PID_coherence(:,2),modal_closed_loop_PID_coherence(:,3))
xlabel('frequency (Hz)')
ylabel('coherence')


% A FIR filter example for ELEC 498

% Generate a signal to filter.  It will contain a sinusoid at 1 kHz and one
% at 4 kHz sampled at 48 ksps

% constants
displaySize = 200;

% create a time base
T = 2;
fs = 48000;
t = 0:1/fs:T;

f1 = 1000;
f2 = 4000;
s1 = 0.5 * sin(2*pi*f1*t);
s2 = 0.5 * sin(2*pi*f2*t);

input = s1 + s2;

figure(1)
subplot(2,1,1);
plot(s1(1:displaySize), 'Linewidth', 2);
hold on;
plot(s2(1:displaySize), 'k', 'Linewidth', 2);
hold off;
grid on
xlabel('Sample #')
ylabel('Amplitude')
title('Input signals')
subplot(2,1,2)
plot(input(1:displaySize), 'g', 'Linewidth', 2);
grid on
xlabel('Sample #')
ylabel('Amplitude')
title('Combined Input Signal (s1 + s2)')

% we can listen to input
%soundsc(input, fs);

% Filter the input signal.  Assumes a filter is present in the workspace h,
% that is a LPF designed to remove the higher frequency tone
output = filter(h53, 1, input);

figure(2);
subplot(2,1,1);
%plot(s1(1:displaySize), 'Linewidth', 2);
plot(input(1:displaySize), 'Linewidth', 2);
axis([1 displaySize -1.0 1.0])
grid on
xlabel('Sample #')
ylabel('Amplitude')
title('Low Freq Input')
subplot(2,1,2);
plot(output(1:displaySize), 'Linewidth', 2);
%plot(output(101:101 + displaySize), 'Linewidth', 2);
grid on
xlabel('Sample #')
ylabel('Amplitude')
title('FilterOutput')
axis([1 displaySize -0.5 0.5])
grid on
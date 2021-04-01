% create a time base
T = 2;
fs = 48000;
t = 0:1/fs:T;

% create 2 pure tone sinusoids
f1 = 1000;
f2 = 4000;
s1 = 0.5 * sin(2*pi*f1*t);
s2 = 0.5 * sin(2*pi*f2*t);

% figure
% plot(t(1,1:48), s1(1,1:48), t(1,1:48), s2(1,1:48));

% set the N-point FFT
N = 128;

% create a frequency base
f = fs*((-N/2):((N-1)/2))/N;

% generate 
S1 = abs(fftshift(fft(s1,N)))/N;
S2 = abs(fftshift(fft(s2,N)))/N;

figure
plot(f, S1, f, S2);
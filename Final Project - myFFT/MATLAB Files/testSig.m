fs = 48000;
f1 = 3500;
N = 128;
t2 = 0:1/fs:(N-1)/fs;

c = cos(2*pi*f1*t2);
s = sin(2*pi*f1*t2);
k = 1;
for i = 1:128
    s2(1, k) = s(1, i);
    k = k + 1;
    s2(1, k) = 0;
    k = k + 1;
end

CopyToC(int16(s2*2^15));

f = -24000:48000/N:24000-48000/N;

plot(f,fftshift(abs(fft(s,128))/N));
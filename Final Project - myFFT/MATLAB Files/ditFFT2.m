N = 128;
fs = 48000;
t = 0:1/fs:(N-1)/fs;
f = -fs/2:fs/N:fs/2-fs/N;
x = sin(2*pi*4500*t);
y = zeros(1,N);
S = fft(x,N);
x = bitrevorder(x)

m = log2(N);
n1 = 0;
n2 = 1;

for p = 1:m
    n1 = n2;
    n2 = n2 + n2;
    e = -6.283185307179586/n2;
    a = 0.0;
    
    for q = 1:n1
        c = cos(a);
        s = sin(a);
        a = a + e;
        
        for z = q:n2:N
            t1 = c * x(1,z + n1) - s * y(1,z + n1);
            t2 = s * x(1,z + n1) + c * y(1,z + n1);
            x(1,z + n1) = x(1,z) - t1;
            y(1,z + n1) = y(1,z) - t2;
            x(1,z) = x(1,z) + t1;
            y(1,z) = y(1,z) + t2;
        end
    end
end

for b = 1:N
    X(1,b) = x(1,b) + 1i * y(1,b);
end

plot(f,fftshift(abs(X)),f,fftshift(abs(S)));
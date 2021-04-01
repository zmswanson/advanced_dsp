N = 128;
fs = 48000;
t = 0:1/fs:(N-1)/fs;
f = -fs/2:fs/N:fs/2-fs/N;
x = sin(2*pi*1000*t);
y = zeros(1,2*N);
S = fft(x,N);
x = bitrevorder(x);

k = 1;
for i = 1:128
    y(1, k) = x(1, i);
    k = k + 1;
    s2(1, k) = 0;
    k = k + 1;
end


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
            t1 = c * y(1,2*(z + n1)) - s * y(1,2*(z + n1)+1);
            t2 = s * y(1,2*(z + n1)) + c * y(1,2*(z + n1)+1);
            y(1,2*(z + n1)) = y(1,2*z) - t1;
            y(1,2*(z + n1)+1) = y(1,2*z) - t2;
            y(1,2*z) = y(1,2*z) + t1;
            y(1,2*z+1) = y(1,z+1) + t2;
        end
    end
end

for b = 1:N
    X(1,b) = y(1,2*b) + 1i * y(1,b);
end

plot(f,fftshift(abs(X)),f,fftshift(abs(S)));
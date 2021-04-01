N = 128;
fs = 48000;
t = 0:1/fs:(N-1)/fs;
f = -fs/2:fs/N:fs/2-fs/N;
s = sin(2*pi*1000*t);
S = fft(s,N);
s = bitrevorder(s);

separation = 1;
r1 = 0;
r2 = 0;

stage = zeros(1,N);
numStages = log2(N);

for p = 1:numStages
    r1 = 0;
    k = 1;
    
    for q = 1:(N/2)
        while eq(stage(1,k), p)
            k = k + 1;
        end
        stage(1,k) = p;
        stage(1,(k + separation)) = p;
        
        a = k;
        b = k + separation;
        
        if r2 >= (N/2)
            r2 = 0;
        end
        
        temp = s(1,a) + s(1,b)*exp(-1i*2*pi*r1/N);
        s(1,b) = s(1,a) - s(1,b)*exp(-1i*2*pi*r1/N);
        s(1,a) = temp;
        
        r2 = r2 + r1;
    end
    
    r1 = r1 / 2;
    separation = separation * 2;
end

plot(f,fftshift(abs(s)),f,fftshift(abs(S)));
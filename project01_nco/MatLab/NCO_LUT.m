LUT = zeros(512,1);

for k = 1:512
    LUT(k,1) = int16(2^15 * sin(2*pi*(k-1)/512));
end

CopyToC(LUT);
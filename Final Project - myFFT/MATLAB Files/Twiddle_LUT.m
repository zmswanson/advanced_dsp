N = 2048;
t = 0:1/N:1 - 1/N;

ReW = cos(-2*pi*t);
ImW = sin(2*pi*t);

CopyToC(int16(ImW*2^15));

% W = zeros(1,2*N);
% 
% j = 1;
% 
% for i = 1:N
%    W(1, j) = ReW(1, i);
%    j = j + 1;
%    W(1, j) = ImW(1, i);
%    j = j + 1;
% end

% W = int16(W * 2^15);
% CopyToC(W);

% plot(W);
plot(t, ReW, t, ImW);
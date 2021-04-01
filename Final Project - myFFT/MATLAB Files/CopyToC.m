function CopyToC(data)
% Copyright Nebraska Embedded Systems Group 2014
%

str = sprintf('int16_t data[] = \n{');

for i = 1:16:length(data)
    strln = sprintf('%6d, ',data(i:min(i+15,length(data))));
    str = [str sprintf('\n    ') strln];
end

str = [str(1:end-1) sprintf('\n};')];
clipboard('copy', str);
end
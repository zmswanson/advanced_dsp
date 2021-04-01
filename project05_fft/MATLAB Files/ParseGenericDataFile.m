function[Result] = ParseGenericDataFile(varargin)
% Copyright Red Cocoa II 2014
%
% Generic Data file parser
 

if nargin < 1
    datatype = 'int16'; 
else
    datatype = varargin{1};
end

% Open file
%if length(varargin) == 0
if nargin < 2
    [FileName,PathName] = uigetfile('*.dat');
    FID = fopen([PathName FileName], 'r');
else
    FID = fopen(varargin{2}, 'r');
end

if FID == -1
    error('fopen error');
end

Result = fread(FID, inf, datatype);
        
% Close file
fclose(FID);


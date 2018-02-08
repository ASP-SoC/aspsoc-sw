clear all; close all;

% number of address bits
N = 12;
NTable = 2^(N);              % Number of values reserved for lookup table
b = 24;
lsb = 2^(-b+1);

% generate table
xTable = 0:2*pi/NTable:2*pi-(2*pi/NTable);
phi = (2*pi / 2/2^N);
Table = int32(sin(xTable + phi) / lsb);

figure; plot(xTable,Table); grid

%f = open('dds_table_14bit.txt');
fid = fopen( 'dds_12bit.txt', 'wt' );


				% ausgabe beistrichgetrennt
for i=1:length(Table)
  fprintf(fid,'%i, ',Table(i));
  if (mod(i, 10)) == 0
    fprintf(fid,'\n');
  end

end

fclose(fid);
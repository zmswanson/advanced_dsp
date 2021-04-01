testVector = 2 * ParseGenericDataFile( 'int16','testVector.dat' ) / 32786;
ccsOut = 2 * ParseGenericDataFile( 'int16', 'outFIR1smp.dat' ) / 32786;
matlabOut = filter( h53, 1, input(1,1:240)');

T = 1/48;
fs = 48000;
t = 0:1:48;
pureSine = 0.5 * sin( 2*pi*1000/fs*t )';

[ h1, w1 ] = freqz( h53, 1, 2048,fs);

mseTest = zeros( 100, 1 );
diff = zeros( 240, 1 );

for m = 1:100
    mseTest( m, 1 ) = immse( pureSine, ccsOut(m:(m+48), 1 ) );
end

for k = 1:240
   diff( k, 1 ) = abs( matlabOut( k, 1 ) - ccsOut( k, 1 ) );
end

mse1 = immse( ccsOut, matlabOut )

figure(1)
subplot( 2, 1, 1 )
plot( 1:1:240, ccsOut, 1:1:240, matlabOut, 'Linewidth', 2 )
grid on
legend( "C Implementation", "MATLAB Result" )
xlabel( "Sample" )
ylabel( "Amplitude" )
subplot( 2, 1, 2 )
plot(diff, 'Linewidth', 2 )
grid on
xlabel( "Sample" )
ylabel( "Absolute Difference" )

figure(2)
plot( w1/1000, 20*log10(abs(h1)), 'Linewidth', 2 );
grid on
xlabel( "Frequency (kHz)" )
ylabel( "Magnitude (dB)" )
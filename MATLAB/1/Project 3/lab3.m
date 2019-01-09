%%ll
%EECOMMS LAB3 3


%% Part 1

[yModFreq500hzAfterEnvelope,tModFreq500hzAfterEnvelope]=getscopedat([7 7],1);

%% Input

subplot(3,1,1)
plot(ypart1fminput)
title('Input Signal')
subplot(3,1,2)
plot(ypart1After30Filter)
title('Signal After 30kHz Filter')
subplot(3,1,3)
plot(ypart1AfterEnvelope)
title('Signal After Envelope Detector')

%% 6 kHz Deviation

subplot(3,1,1)
plot(ypart1Input6kDev)
title('Input Signal')
subplot(3,1,2)
plot(ypart1After30K6kDev)
title('Signal After 30kHz Filter')
subplot(3,1,3)
plot(ypart1AfterEnvelope6kDev)
title('Signal After Envelope Detector')

%% 23 kHz Deviation

subplot(3,1,1)
plot(ypart1FMinput23KDev)
title('Input Signal')
subplot(3,1,2)
plot(ypart1After30K23KDev)
title('Signal After 30kHz Filter')
subplot(3,1,3)
plot(ypart1AfterEnvelope23KDev)
title('Signal After Envelope Detector')

%% fm 500 Hz modulation

subplot(3,1,1)
plot(yModFreq500hzInput)
title('Input Signal')
subplot(3,1,2)
plot(yModFreq500hzAfter30k)
title('Signal After 30kHz Filter')
subplot(3,1,3)
plot(yModFreq500hzAfterEnvelope)
title('Signal After Envelope Detector')

%% Spectrum IO

subplot(3,1,1)
plot(abs(fftshift(fft(ypart1fminput))))
title('Input Signal Spectrum')
subplot(3,1,2)
plot(abs(fftshift(fft(ypart1After30Filter))))
title('Spectrum ofSignal After 30kHz Filter')
subplot(3,1,3)
plot(abs(fftshift(fft(ypart1AfterEnvelope))))
title('Spectrum of Signal After Envelope Detector')

%% Part 2

subplot(2,1,1)
plot(Part_2_10K_1V)
title('Varying Modulating Freq. 10 kHz')
subplot(2,1,2)
plot(Part_2_1K_1V)
title('Varying Modulating Freq. 1 kHz')

%% Varying Amplitude (Voltage)

subplot(3,1,1)
plot(Part_2_1K_point5V)
title('Varying Amplitude 0.5 V')
subplot(3,1,2)
plot(Part_2_1K_1p5V)
title('Varying Amplitude 1.5 V')
subplot(3,1,3)
plot(Part_2_1K_2V)
title('Varying Amplitude 2 V')

%% Performance Threshold

subplot(2,1,2)
plot(Part_2_20k_1V)
title('Performance Range 20 kHz')
subplot(2,1,1)
plot(Part_2_500h_1V)
title('Performance Range 500 Hz')

%% Part 4

subplot(3,1,1)
plot(Part_4_Demod_99_7)
title('Demodulator Rx, F_c 99.7 MHz')
subplot(3,1,2)
plot(Part_4_Demod_99_9)
title('Demodulator Rx, F_c 99.9 MHz')
subplot(3,1,3)
plot(Part_4_Demod_100_1)
title('Demodulator Rx, F_c 100.1 MHz')

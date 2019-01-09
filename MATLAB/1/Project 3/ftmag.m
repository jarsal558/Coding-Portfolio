function [f,W] = ftmag(t,y)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Spits out fft magnitude in hertz
%Matt Donow, ECE Dept., Rowan University
%
%Function Usage: [f,W] = ftmag(t,y)
%
%Purpose:
%Calculates the frequency axis for plotting and fft magnitude in hertz
%
%

%
%Function Inputs:
%t: Time vector
%y: Time domain amplitude vector

%
%Function Outputs
%f: frequency axis(hertz)
%W: Magnitude FFT of w(t)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
T=t((length(t)))-t(1);
N=length(t);
dt=T/N;
n=0:N-1;
fs=1/dt;
%f=n/T;
W = fftshift((abs(fft(y))));
f = linspace(-fs/2,fs/2, length(y));



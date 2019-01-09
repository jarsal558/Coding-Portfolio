%% Problem 1/2

f1 = input('Enter f1: ');
f2 = input('Enter f2: ');
N = input('Enter Length of Signal, N: ');
R = input('Enter Length of DFT, R: ');
n = 1:N;

for n = 1:N    
     x(n) = (1/2)*sin(2*pi*f1*n) + sin(2*pi*f2*n);     
end

y = fft(x,R);
X = abs(y);
plot(X)


%% Problem 3

f1 = input('Enter f1: ');
f2 = input('Enter f2: ');
N = input('Enter Length of Signal, N: ');
R = input('Enter Length of DFT, R: ');
n = 1:N;

for n = 1:N    
     x(n) = 0.85*sin(2*pi*f1*n) + sin(2*pi*f2*n);     
end

y = fft(x,R);
X = abs(y);
subplot(2,1,1),plot(X)

W = hamming(length(x));
Y = fft(x'.*W);
Z = abs(Y);
subplot(2,1,2), plot(Z);


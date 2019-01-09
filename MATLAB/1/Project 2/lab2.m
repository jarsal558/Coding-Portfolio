%Lab 2 Data Collection

%% Part 1

%% mod 100%

figure()
[d100o, t100o] = getscopedat([7 7],1); % Graphs Channel 1 (Output Signal) mod 100
hold on

[d100i, t100i] = getscopedat([7 7],2);% Graphs Channel 2  (input Signal) mod 100

%% mod 120%

x
figure()

[d120o, t120o] = getscopedat([7 7],1); % Graphs Channel 1 (Output Signal) 
hold on

[d120i, t120i] = getscopedat([7 7],2);% Graphs Channel 2  (input Signal) 

%% mod 50%

figure()
[d50o, t50o] = getscopedat([7 7],1); % Graphs Channel 1 (Output Signal) 
hold on

[d50i, t50i] = getscopedat([7 7],2);% Graphs Channel 2  (input Signal) 

%% mod 10%
figure()
[d10o, t10o] = getscopedat([7 7],1); % Graphs Channel 1 (Output Signal) 
hold on

[d10i, t10i] = getscopedat([7 7],2);% Graphs Channel 2  (input Signal) 

%%
% Carrier about below 100khz, its messes with the envelop. It 
% starts showing periodic content of the carrier frequency bleeds through
% 170 mvpp for 3db thing down from 200 mvpp

%% EComms Lab 1 Resource for Lab 2

%Specify SNR
snr=10;

%Generate Asharp signal
t=(0:1/8e3:1)';
s = 0.5*sin(2*pi*466.16*t); 
figure(1)
plot(s)
sound(s);
wavwrite(s, 'asharp.wav');
save asharp.csv -ascii s;


%Compute signal variance
var_s = cov(s);

%Calculate required noise variance
var_noise=var_s/(10^(snr/10));

%Generate noise
n=sqrt(var_noise)*randn(length(s),1);
sound(n);

%Add signal to noise and generate message
m=s+n;
sound(m);
wavwrite(m,'asharp_noise.wav');
save asharp_noise.csv -ascii m;

writefunc([10 7],m)

[singlegousei,tgousei]=getscopedat([7 7],2); %input 2
[singlegouseo,tgouseo]=getscopedat([7 7],1); %output channel 1

%% Multi-Tone Signal Data Collection

[multii,multiti]=getscopedat([7 7],3); %input 2
[multio,multito]=getscopedat([7 7],2); %output channel 1


%% Part 2

%% 

[dsbScBottomNully,dsbScBottomNullt]=getscopedat([7 7],2);


%% Varying Amplitude

%100 mv
[mv100y,mv100t]=getscopedat([7 7],2);

%500 mv
[mv500y,mv500t]=getscopedat([7 7],2);

%2.5 v
[mv2500y,mv2500t]=getscopedat([7 7],2);

%% Multi-Tone Signal Data COllection

[multiy,multit]=getscopedat([7 7],2);


%% EComms Lab 1 Resource for Lab 2

%Specify SNR
snr=3;

%Generate Asharp signal
t=(0:1/8e3:1.0)';
su = 5*sin(2*pi*466.16.*t);
s=(1+su).*cos(2*pi*600000.*t)
figure(1)
plot(s)
%sound(s);
%wavwrite(s, 'asharp.wav');
%save asharp.csv -ascii s;


%Compute signal variance
var_s = cov(s);

%Calculate required noise variance
var_noise=var_s/(10^(snr/10));

%Generate noise
n=sqrt(var_noise)*randn(length(s),1);
%sound(n);

%Add signal to noise and generate message
m=s+n;
m=m./max(m)
%sound(m);
%wavwrite(m,'asharp_noise.wav');
%save asharp_noise.csv -ascii m;

writefunc([11 7],m)

%[singlegousei,tgousei]=getscopedat([7 7],2); %input 2
%[singlegouseo,tgouseo]=getscopedat([7 7],1); %output channel 1

% AM Detection Fails Between SNR 4 and 5

%% EComms Lab 1 Resource for Lab 2

%Specify SNR
snr=4;

%Generate Asharp signal
t=(0:1/8e3:1.0)';
su = 5*sin(2*pi*466.16.*t);
s=(1+su).*cos(2*pi*600000.*t)
figure(1)
plot(s)
%sound(s);
%wavwrite(s, 'asharp.wav');
%save asharp.csv -ascii s;


%Compute signal variance
var_s = cov(s);

%Calculate required noise variance
var_noise=var_s/(10^(snr/10));

%Generate noise
n=sqrt(var_noise)*randn(length(s),1);
%sound(n);

%Add signal to noise and generate message
m=s+n;
m=m./max(m)
%sound(m);
%wavwrite(m,'asharp_noise.wav');
%save asharp_noise.csv -ascii m;

writefunc([11 7],m,1,1)

%[singlegousei,tgousei]=getscopedat([7 7],2); %input 2
%[singlegouseo,tgouseo]=getscopedat([7 7],1); %output channel 1

% AM Fails Between SNR 4 and 5
% DSB-SC Also Fails Between 4 and 5
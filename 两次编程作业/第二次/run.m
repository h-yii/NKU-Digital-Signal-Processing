t=0:1:256; %采样步长
y = cos(0.1*t)+cos(0.4*t);%时域，原信号
% plot(t,y);%原有信号

h=[-6.76195,13.456335,-6.76195];
result1=conv(y,h);%滤波结果！


x1=1:259;
y1=cos(0.4*x1);
figure(2);
plot(1:259,result1);
% hold on;
% plot(x1,y1);
% hold off;
for i=4:257
    h(i)=0;
end
Y = fft(y);
H = fft(h);
result2=Y.*H;
result3=ifft(result2);
hold on;
plot(1:257,result3);
hold off;


% N=length(t); %样点个数


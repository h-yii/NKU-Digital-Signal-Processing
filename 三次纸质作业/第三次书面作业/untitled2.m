x=0:pi/100:4*pi;
y=cos(x).*exp(1*i*(-2)*x);% H 频响
% plot(x,y);
% set(gca,'xlim',[0,4.*pi]);%设置x轴坐标范围
% set(gca,'xtick',0:pi/2:4*pi);%设置x轴坐标间隔
% set(gca,'XTickLabel',{'0','\pi/2','\pi','3\pi/2','2\pi'});%\pi=π
figure(3);
plot(x,angle(y));
set(gca,'xlim',[0,4.*pi]);%设置x轴坐标范围
set(gca,'xtick',0:pi/2:4*pi);%设置x轴坐标间隔
set(gca,'XTickLabel',{'0','\pi/2','\pi','3\pi/2','2\pi','5\pi/2','3\pi','7\pi/2','4\pi'});%\pi=π


% figure(2);
% plot(x,abs(y));
% set(gca,'xlim',[0,4.*pi]);%设置x轴坐标范围
% set(gca,'xtick',0:pi/2:4*pi);%设置x轴坐标间隔
% set(gca,'XTickLabel',{'0','\pi/2','\pi','3\pi/2','2\pi'});%\pi=π



% t=0:pi/100:2*pi;
% x=sin(t);
% y1=[-0.25,0.5,-0.25];
% r1=conv(x,y1);
% for u=4:201
%     y1(u)=0;
% end
% y2=fft(y1);
% 
% r2=x.*y2;
% 
% 
% plot(t,r2);
% t(202)=0;
% t(203)=0;
% figure(2);
% plot(t,r1);

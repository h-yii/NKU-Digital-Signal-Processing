function [xk] = dft(x1)
N=length(x1);
xk=zeros(1,N);
for m=0:N-1
    sum=0.0;
    for k=0:N-1
        sum=sum+x1(k+1)*exp(-1j*2*pi*m*k/N);
    end
    xk(m+1)=sum;
end
% xk
% idft(xk)

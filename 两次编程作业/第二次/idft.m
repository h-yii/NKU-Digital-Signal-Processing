function [x] = idft(xk)
N=length(xk);
x=zeros(1,N);
for I=0:N-1
    sum=0.0;
    for k=0:N-1
        sum=sum+xk(k+1)*exp(1j*2*pi*I*k/N)/N;
    end
    x(I+1)=sum;
end

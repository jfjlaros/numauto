function [mu,vec] = powermethod(A,x,tol,N)

% power vec = powermethod(A,x,tol,N) 

x=x./max(x)
k=1
error=2*tol

while k<=N & error>tol,
  y=A*x
  mu=max(y)
  y=y./mu
  error=max(abs(x-y))
  x=y
end

vec=x

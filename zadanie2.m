t = 0:0.01:10;
y = abs(sin(t));
omega = 2;
z = 2/pi;
for n=1:50
	z=z+1/(1-4*n^2)*cos(n*omega*t)
	endfor;

plot(t,y, t,z, axis( [0 10 -2 2] ))
	

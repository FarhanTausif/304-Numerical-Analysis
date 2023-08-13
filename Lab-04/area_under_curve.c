#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define n 10000
#define EPSILON 10e-6

#define f(x) sqrt(x)
#define g(x) (x)*(x)
#define h(x) ((f(x)) - (g(x)))

double bisection(double a, double b);

int main(){
	
	double a = 0.0, b,x1 = 0.5, x2 = 1.25, h, Sum_X, Sum_O, Sum_E;
	double x[n], y[n];
	int i;
	
	b = bisection(x1, x2);
	
	h = (b - a) / (n - 1);
		
	x[0] = a;
	
	for(int i = 1; i < n-1; ++i){
		x[i] = x[i-1] + h;
	}
	
	x[n - 1] = b;
	
	for(int i = 0; i < n; ++i){
		y[i] = h(x[i]);
	}
	
	Sum_X = (y[0] + y[n-1]);
	
	for(int i = 1; i < n-1; i++){
		if(i % 2 == 0) Sum_E += y[i];
		else Sum_O += y[i];
	}
	
	double I = h*(Sum_X + 4*Sum_O + 2*Sum_E)/3;
	
	printf("Simpson's 1/3 Rule- - - - - - - - - - - \n");
	printf("Integral Value = %lf\n", I);
	printf("- - - - - - - - - - - - - - - - - - - -  \n");
		
	return 0;
}

double bisection(double a, double b){
	
	double c;
	
	if(h(a) * h(b) > 0) exit(EXIT_FAILURE);
	
	for(int i = 1; i < n; ++i){
	
		c = (a+b)/2;
	
		if(fabs(h(c))<EPSILON) return c;
	
		if(h(a) * h(c) < 0) b = c;
		else a = c;
	}
	
	printf("[%9lf,%9lf]: Loop Overflow!!!\n", a, b);
	exit(EXIT_FAILURE);
}


#include<stdio.h>
#include<math.h>

#define n 11

#define f(x) (x)*(x) + 1

int main(){
	
	int i;
	double a, b, h, Sum_X, Sum_O, Sum_E, I;
	printf("Enter boundary values:");
	scanf("%lf %lf", &a, &b);
	
	h = (b - a) / (n - 1);
	
	double x[n], y[n];
	
	x[0] = a;
	
	for(i = 1; i < n-1; ++i){
		x[i] = x[i-1] + h;
	}
	
	x[n - 1] = b;
	
	for(i = 0; i < n; ++i){
		y[i] = f(x[i]);
	}
	
	Sum_X = (y[0] + y[n-1]);
	
	
	for(i = 1; i < n-1; i++){
		if(i % 2 == 0) Sum_E += y[i];
		else Sum_O += y[i];
	}
	
	I = h*(Sum_X + 4*Sum_O + 2*Sum_E)/3;
	
	printf("Simpson's 1/3 Rule- - - - - - - - - - - \n");
	printf("Integral Value = %lf\n", I);
	printf("- - - - - - - - - - - - - - - - - - - -  \n");
	
	
	return 0;
}

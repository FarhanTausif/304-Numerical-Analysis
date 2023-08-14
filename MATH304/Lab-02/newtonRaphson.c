#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#define f(x) ( x*x*x + 4*x*x -10 )
#define df(x) (3*x*x + 8*x)

#define TOLERANCE 0.1e-5

double x0, x1;

void newtonRaphsonMethod(int it); 

int main(void){
	printf("Enter two boundary values: ");
	scanf("%lf %lf", &x0, &x1);
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		printf(" Iter\t      x0\t     x1\t\t   f(x0)\t    f'(x0)\t    f(x1)\n");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		newtonRaphsonMethod(1);
	
}


void newtonRaphsonMethod(int it){
	x1 = x0 - (f(x0)/df(x0));
	if(it<10) printf("  0%d     %10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n",it, x0, x1, f(x0), df(x0), f(x1));		
	else printf("  %d     %10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n",it, x0, x1, f(x0), df(x0), f(x1));		
	if(fabs(f(x1)) < TOLERANCE){
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		printf("Root: %lf\n", x1);
		return;
	}else{
		x0 = x1;
		newtonRaphsonMethod(it+1);
	}
	
}

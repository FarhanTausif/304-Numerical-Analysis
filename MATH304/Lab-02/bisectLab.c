#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#define f(x) ( x*x*x + 4*x*x -10 )
#define TOLERANCE 0.1e-5

double a, b, c;

bool checkRoot(double a, double b);
void bisectionMethod(int it); 

int main(void){
	printf("Enter two boundary values: ");
	scanf("%lf %lf", &a, &b);
	
	if(!checkRoot(a,b)){
		printf("Root doesn't exist in the interval: [%.2lf,%.2lf]", a, b);
		exit(0);
	}else{
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		printf("Iter\t\ta\t\tb\t\tc\t\tf(a)\t\tf(b)\t\tf(c)\n");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		bisectionMethod(1);
	}
}


bool checkRoot(double a, double b){
	return f(a)* f(b) < 0; 
}

void bisectionMethod(int it){
	c = (a+b)/2;
	if(it<10) printf("  0%d     %10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n",it, a, b, c, f(a), f(b), f(c));		
	else printf("  %d     %10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n",it, a, b, c, f(a), f(b), f(c));		
	if(fabs(f(c)) < TOLERANCE){
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		printf("Root: %lf\n", c);
		return;
	}else{
		if(checkRoot(a,c)){
			b = c;
			bisectionMethod(it+1);
		}else{
			a = c;
			bisectionMethod(it+1);
		}
	}
	
}

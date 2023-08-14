#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
/*
	int a = 10, *pa;
	pa = &a;
	*pa = 25;
	*(&a) = 25;	
*/
#define f(x) (x*x - 5*x + 6)
#define EPSILON 10e-7

double a, b, c;

void __init__bounds__(double x, double y);
bool existsRoot(double x, double y);
void falseMethod();

int main(){
	
	printf("Enter two bound values:");
	scanf("%lf %lf", &a, &b);
	
	__init__bounds__(a,b);
	
	printf("a: %lf b: %lf\n", a, b);
	
	// f(3.0) = 0.0 < 0.0005 
	
	/*if( f(b) == 0.00){
		printf("f(b): %lf\tRoot: %lf\n",f(b), b);
		exit(0);
	}*/
	
	if(!existsRoot(a,b)){
		printf("Root doesn't exist!\n");
		exit(0);
	} 
	else{
		falseMethod();
	}
	
	
}


void __init__bounds__(double x, double y){
	*(&a) = x; //a = x;
	*(&b) = y; //b = y;
}

bool existsRoot(double x, double y){
	//printf("f(a): %lf f(b): %lf\n", f(x), f(y));
	return f(x) * f(y) <= 0; 
}

void falseMethod(){
	
	c = ( b*f(a) - a*f(b) )/( f(a) - f(b) ); // c = 0+3.5/2 = 1.75
	//printf("c: %lf\n", c);
	
	if(fabs(f(c)) < EPSILON){
		printf("Root: %.2lf\n", c);
		return;
	} 
	else{
		if(existsRoot(a,c)){
			b = c;
			falseMethod();
		}else{
			a = c;
			falseMethod();
		}
	} 
	
	
}

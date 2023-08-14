#include<stdio.h>
#include<math.h>
#define PI 3.14159265
int main(void ){
	int n = 100;
	double x, a = 0.0, b= 2*PI, h;
	h = (b-a)/n;
	
	printf(" \"x\",\"tan(x)\"\n");
	x = a;
	for(int i = 1; i <= n; i++){
		x+=h;
		printf("%lf,%lf\n", x, tan(x));
	}
	
	//x = b;
	
	//printf("%lf,%lf\n", x, sin(x));
	
	
}

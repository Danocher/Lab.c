#include <stdio.h>
#include <math.h>
//#include <stdlib.h>

double f1(double x){
    return cos(x)*exp(-(x*x));
}

double f2(double x){
    double x_1;
    x_1 = 4-x*x >=0 ? 4-x*x : 0;
    return log(x+1)-sqrt(x_1);
}

double rectangular(double n, double h){
    double integral = 0, f;
    int i;
    for(i = 0;i<n;i++){
        if (i <= (int)n/2){
            f = f1(i*h + h/2);
        }
        else{
            f = f2(i*h + h/2);
        }
        integral += h*f;
    }
    return integral;
}
int main()
{
   double E, h, integral1=0, integral2=1;
   printf("Enter E -> ");
   scanf("%lf", &E);
   double a = 0, b = 2, n = 2;
   h = ((b-a)/n);
   while (fabs((integral2 - integral1)/3) > E){
       integral1 = rectangular(n, h);
       //printf("%lf\n", integral1);
       n *= 2;
       h = ((b-a)/n);
       integral2 = rectangular(n, h);
       //printf("%.5lf\n", integral2);
   }
   printf("%.5lf", integral2);
   
}

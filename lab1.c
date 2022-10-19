#include <stdio.h>
#include <math.h>

int main()
{
 int a, b, c, x, min, forElser, d;
 float elser;
    printf("Enter a -> ");
    scanf("%d", &a);
    printf("Enter b -> ");
    scanf("%d", &b);
    printf("Enter c -> ");
    scanf("%d", &c);
    printf("Enter x -> ");
    scanf("%d", &x);
    if ((a < b) && (a < c)){
        min = a;
        d = b+c;
    }
    else if ((b < a) && (b < c)){
        min = b;
        d = a+c;
    }
    else 
        min = c;
        d = a+b;
    }

    forElser = min % 7;
    if ((min <= x) && (forElser == 0))
        printf("MIN = %d", min);
    else{
        elser = (float)min/d;
        printf("%f", elser);
    }
}

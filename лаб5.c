#include <stdio.h>
#include <math.h>

int s1mple(int n, int a){
    if (a==1){
        return 1;
    }
    else if (n % a != 0) {
            return s1mple(n, a-1);
        
    }
        else {
            return 0;
        }
}
int simple(int b){
    int z = 0, i;
    for (i = 1; i<=b-2; i++){
        //printf("%d", z);
        if (b%(b-i) ==0){
            //b = b-1;
            z += 1;
        }
        //else{
         //   break;
        //}
        
    }
    if (z > 0){
        printf("cycle: number isn't simple\n");
    }
    else{
        printf("cycle: number is simple\n");
    }
    
}
int main()
{
    int num;
    scanf("%d", &num);
    if (s1mple(num, num-1) == 1){
        printf("recursion: number is simple\n");
    }
    else{
        printf("recursion: number isn't simple\n");
    }
    simple(num);
}
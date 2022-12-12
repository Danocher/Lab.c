#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () % 101 - 50;
}

int max_mas(int a[], int n){
    int max_1 = -51, max_2 = -51, max_3 = -51, i, i_1=-1, i_2=-1, i_3=-1, j;
    for(i = 0; i<n;i++){
        if ((max_1<a[i]) && (i != i_1)){
        max_1 = a[i];
        i_1 = i;
        }
        
    }
    for(i = 0; i<n;i++){
        if ((max_2<a[i]) && (i != i_1)){
        max_2 = a[i];
        i_2 = i;
        }
        
    }
    for(j = 0; j<n;j++){
        if ((max_3<a[j]) && (j != i_2) && (j != i_1)){
        max_3 = a[j];
        i_3 = j;
        }
    }
    // printf("%d\n", i_1);
    // printf("%d\n", i_2);
    // printf("%d\n", i_3);
    printf("%d\n", max_1);
    printf("%d\n", max_2);
    printf("%d\n", max_3);
    return (max_3*max_1*max_2)-((i_1+i_3+i_2)%n);
    
}

int main()
{
    srand(time(NULL));
    int n, max;
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    int i;
    for (i = 0; i < n; i++)
        printf("%4d", A[i]);
    printf("\n");
    max = max_mas(A, n);
    printf("%d\n", max);
    return 0;
    
}
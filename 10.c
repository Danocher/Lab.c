#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fail()
{
    printf("Memory allocation failure!\n");
    exit(EXIT_FAILURE);
}

void fill(int n, int k, int * a)
{
	int i, j;
    for (i = 0; i < n; i++)
        for(j = 0; j < k; j++)
            a[i * k + j] = rand () % 101;
}

double answer(int n, int k, int * a){
    int i, j, sled=0, skal=0;
    double ans;
    for (i = 0; i < n; i++){
        for(j = 0; j < k; j++){
            if (i == j){
                sled += a[i * k + j];
            }
            skal += a[i * n + j] * a[j * k + i];        
        } 
    }
    //printf("sled = %d", sled);
    ans = (double)sled / skal;
    return ans;
}
int main()
{
    srand(time(NULL));
    int A, B;
    printf("Матрица размером А*A \n");
    printf("A -> ");
    scanf("%d", &A);
    B = A;
    int *a = (int *)malloc(A * B * sizeof(int));
    if(!a)
    	fail();
    fill(A, B, a);
    int i, j;
    for (i = 0; i < A; i++){
        for(j = 0; j < B; j++){
            printf("%4d", a[i * B + j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("%lf\n", answer(A, B, a));
    return 0;
}

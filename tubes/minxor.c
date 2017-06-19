#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int findMinXor(int* A, int n1) {
    int i;
    int j;
    int min=INT_MAX;
    for(i=0;i<n1;i++) {
        for(j=i+1;j<n1;j++) {
            printf("%d, %d = %d\n",i,j,A[i]^A[j]);
            if( min > (A[i]^A[j])) {
                min = A[i]^A[j];
            }
        }
    }
    return min;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int findMinXor2(int* A, int n1) {
    int i;
    qsort(A,n1,sizeof(int),cmpfunc);
    int min = (A[0]^A[1]);
    for(i=2;i<n1-1;i++) {
        if(min>(A[i]^A[i+1])) min = (A[i]^A[i+1]);
    }
    return min;
}

int main() {
    int a[4] = {12,4,6,2};
    printf("\n%d\n",findMinXor2(a,4));
    return 0;
}
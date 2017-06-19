#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
    if( *(double*)a > *(double*)b )
        return 1;
    else if( *(double*)a < *(double*)b )
        return -1;
    else
        return 0;
}

int main()
{
    int N,M;
    long long A[1000][1000];
    long long i,j,k,a,b;
    long long min=1000000000,current,start,end,mid;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            scanf("%lld",&A[i][j]);
        }
    }
    
    for(i=0;i<N;i++) {
        qsort(A[i],M,sizeof(long long),cmpfunc);
    }
    
    for(i=0;i<N-1;i++) {
        for(j=0;j<M;j++) {
            current = A[i][j];
            start = 0;
            end = M-1;
            while(start<=end) {
                mid = (start+end)/2;
                if(current==A[i+1][mid])
                    break;
                else if(current<A[i+1][mid])
                    end = mid-1;
                else if(current>A[i+1][mid])
                    start = mid+1;
            }
            printf("mid is %d\n",mid);

            if(mid<M-1 && A[i+1][mid]<=current) {
                a = mid;
                b = mid+1;
                if(abs(A[i+1][a]-current)<min) 
                    min = abs(A[i+1][a]-current);
                if(abs(A[i+1][b]-current)<min) 
                    min = abs(A[i+1][b]-current);
            }
            else if(mid>0) {
                a = mid-1;
                b = mid;
                if(abs(A[i+1][a]-current)<min) 
                    min = abs(A[i+1][a]-current);
                if(abs(A[i+1][b]-current)<min) 
                    min = abs(A[i+1][b]-current);
            }
            else {
                if(abs(A[i+1][mid]-current)<min) 
                    min = abs(A[i+1][mid]-current);
            }
            
        }
    }
    
    printf("%lld\n",min);
    return 0;
}

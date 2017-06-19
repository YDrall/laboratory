#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
    if( *(long long*)a > *(long long*)b )
        return 1;
    else if( *(long long*)a < *(long long*)b )
        return -1;
    else
        return 0;
}

long long search(long long *A, long long size, long long element) {
    long long start=0;
    long long end = size-1;
    long long mid;
    long long first=-1;
    long long last =-1;
    long long el = element*element;
    while(start<=end) {
        mid = (start+end)/2;
        if(el==A[mid]) {
            first = mid;
            end = mid-1;
        }
        else if(el<A[mid])
            end = mid-1;
        else if (el >A[mid])
            start = mid+1;
    }
    
    if(first == -1) {
        if( A[mid]<el)
            return mid+1;
        else
            return mid;    
    }
    else {
        start = first;
        last = first;
        end = size-1;
        while(start<=end) {
            mid = (start+end)/2;
            if(el==A[mid]) {
                last = mid;
                start = mid+1;
            }
            else if(el<A[mid])
                end = mid-1;
            else if (el >A[mid])
                start = mid+1;
        }
        
        if( A[last]<el)
            return last+1;
        else
            return last;
    }
}

int main()
{
    long long N;
    long long coord[100000];
    long long x,y;
    long long q;
    long long r;
    long long i;
    scanf("%lld",&N);
    for(i=0;i<N;i++) {
        scanf("%lld %lld",&x,&y);
        coord[i]= x*x + y*y;
    }
    
    qsort(coord,N,sizeof(long long),cmpfunc);
    
    scanf("%lld",&q);
    for(i=0;i<q;i++) {
        scanf("%lld",&r);
        printf("%lld\n",search(coord,N,r));
    }
    return 0;
}

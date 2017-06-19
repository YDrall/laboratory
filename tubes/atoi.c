#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int is_overflow(int a, int b) {
    if(b < 0) {
        return (a < INT_MIN - b);
    }
    return (a > INT_MAX - b);

}


int matoi(const char* A) {
    int ans =0;
    int sign=1;
    int *res = malloc(sizeof(int));

    int i=0;
    // skip all spaces
    while(A[i]!='\0') {
        if(A[i]==' ') i++;
        else break;
    }
    // if no numeric character found return 0
    if(A[i]<'0' || A[i]>'9' ) {
        if(A[i]=='-') {
            sign =-1;
            i++;
        }
        if(A[i]=='+') {
            sign =1;
            i++;
        }
        if(A[i]<'0' || A[i]>'9' ) return 0;
    }
    
    while(A[i]!='\0') {
        if(A[i]<'0' || A[i]>'9') break;
        else {
         if(ans<0 && ( __builtin_mul_overflow(ans,10,res) ||  __builtin_add_overflow(ans*10,A[i]-'0',res) ) )
            return INT_MIN;
         else if(ans>0 && (__builtin_mul_overflow(ans,10,res) ||  __builtin_add_overflow(ans*10,A[i]-'0',res) ) )
            return INT_MAX;
         else ans = ans*10+A[i]-'0';
        }
        i++;
    }
    return sign*ans;
}


int main() {
    int mino = -21323;
    int maxo = 2147483646;
    int *res;
    // printf("%d\n",__builtin_mul_overflow(maxo,10,res));
    // printf("%d\n",maxo+82);
    printf("%d\n",matoi(" -88297 248252140B12"));
    return 0;
}
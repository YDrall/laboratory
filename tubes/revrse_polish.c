#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1=1;
    char A[][3] = {"-1"};

    int i;
    int stack[n1];
    int top=-1;
    int result =0;
    for(i=0;i<n1;i++) {
        if(*A[i] == '+') {
            printf("op is + and top is %d, stack[top] is %d, stack[top-1] is %d",top,stack[top],stack[top-1]);
            stack[top-1] = stack[top] + stack[top-1];
            top--;
        }
        else if( *A[i] == '-') {
            printf("op is - and top is %d, stack[top] is %d, stack[top-1] is %d",top,stack[top],stack[top-1]);
            stack[top-1] = stack[top] - stack[top-1];
            top--;
        }
        else if( *A[i] == '*') {
            printf("op is * and top is %d, stack[top] is %d, stack[top-1] is %d",top,stack[top],stack[top-1]);
            stack[top-1] = stack[top] * stack[top-1];
            top--;
        }
        else if( *A[i] == '/') {
            printf("op is / and top is %d, stack[top] is %d, stack[top-1] is %d",top,stack[top],stack[top-1]);
            stack[top-1] = stack[top] / stack[top-1];
            top--;
        }
        else {
            top++;
            stack[top] = atoi(A[i]);
        }
    }
    
    printf("\n%d\n",stack[0]);
}
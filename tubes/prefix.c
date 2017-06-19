#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * @input A : array of strings termination by '\0'
 * @input n1 : number of strings in array A
 * 
 * @Output string. Make sure the string is '\0' terminated.
 */
char* longestCommonPrefix(char A[10][100], int n1) {
    int smallest =INT_MAX;
    int sIndex;
    int i,j;
    for(i=0;i<n1;i++) {
        j=0;
        while(A[i][j]!='\0')
            j++;
        if(j<smallest) {
            smallest =j;
            sIndex =i;
        }
    }
    int size=0;
    int m=1;
    for(i=0;i<smallest;i++) {
        for(j=0;j<n1;j++) {
            if(A[sIndex][i]!=A[j][i]) {
                m=0;
                break;
            }
        }
        if(m==0)
            break;
        size++;
    }
    
    char *r = (char*)malloc(sizeof(char)*size);
    for(j=0;j<size;j++) {
        r[j] = A[sIndex][j];
    }
    
    return r;
}


int main() {
    char A[10][100] = {
        "ABCD\0"
    };
    printf("%s\n",longestCommonPrefix(A,1));
    return 0;
}
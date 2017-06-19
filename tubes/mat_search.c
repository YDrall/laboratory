#include <stdio.h>

/**
 * @input A : 2D integer array ' * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * @input B : Integer
 * 
 * @Output Integer
 */
int searchMatrix(int A[4][5], int n11, int n12, int B) {
    int start = 0;
    int end = n11-1;
    int mid=0;
    while(start<=end) {
        mid = (start+end)/2;
        if(B==A[mid][0])
            return 1;
        else if(B<A[mid][0])
            end = mid-1;
        else if(B> A[mid][0])
            start = mid +1;
    }
    
    if(A[mid][0]>B)
        mid -=1;
    start = 0;
    end = n12-1;
    printf("mid row is %d\n",mid);
    int row_mid=0;
    while(start<=end) {
        row_mid = (start+end)/2;
        if(B==A[mid][row_mid])
            return 1;
        else if(B<A[mid][row_mid])
            end = row_mid-1;
        else if(B>A[mid][row_mid])
            start = row_mid+1;
    }

    return 0;
}

int main() {
    int A[4][5] = {
        {1,5,7,8,9},
        {10,12,18,20,23},
        {23,26,27,30,33},
        {44,62,66,76,90}
    };
    printf("%d\n",searchMatrix(A,4,5,66));
    return 0;
}
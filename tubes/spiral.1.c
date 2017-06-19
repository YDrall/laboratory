#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : Read only ( DON'T MODIFY ) 2D integer array ' * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* spiralOrder(const int** A, int n11, int n12, int *length_of_array) {

	 
	 *length_of_array = n11 * n12; // length of result array
	 int *result = (int *) malloc(*length_of_array * sizeof(int));
	 int top = 0;
	 int bottom = n11;
	 int left = 0;
	 int right =n12;
	 int dir =0;
	 int iterator;
	 while(top<=bottom && left<=right) {
	     if(dir==0) {
	         for(iterator=left;iterator<right;iterator++) {
	             printf("%d",A[top][iterator]);
	             dir=1;
	         }
	     }
	     else if(dir==1) {
	         for(iterator=top;iterator<bottom;iterator++) {
	             printf("%d",A[iterator][right]);
	             dir=2;
	         }
	     }
	     else if(dir==2) {
	         for(iterator=right;iterator<left;iterator--) {
	             printf("%d",A[bottom][iterator]);
	             dir=3;
	         }
	     }
	     else if(dir==4) {
	         for(iterator=bottom;iterator>top;iterator--) {
	             printf("%d",A[left][iterator]);
	             dir=1;
	         }
	     }
	 }
	 return result;
}

int main() {
    int n11=7;
    int n12 = 6;
    int length_of_array = n11*n12;
    int A[7][6] = {
        {1,2,3,4,5,6},
        {22,23,24,25,26,7},
        {21,36,37,38,27,8},
        {20,35,42,39,28,9},
        {19,34,41,40,29,10},
        {18,33,32,31,30,11},
        {17,16,15,14,13,12}
    };
	// int A[1][1] = {{1}};
    // spiralOrder(A,n11,n12,&length);
     int *result = (int *) malloc(length_of_array * sizeof(int));
	 int top = 0;
	 int bottom = n11-1;
	 int left = 0;
	 int right =n12-1;
	 int dir =0;
	 int iterator;
	 int result_iterator=0;
	 while(top<=bottom && left<=right) {
	     
	         for(iterator=left;iterator<=right;iterator++) {
	             result[result_iterator] = A[top][iterator];
	             result_iterator++;
	         }
	         dir=1;
	         top++;
	     
	     
	         for(iterator=top;iterator<=bottom;iterator++) {
	             result[result_iterator] =A[iterator][right];
	             result_iterator++;
	         }
	        right--;
	     
	     
	         for(iterator=right;iterator>=left;iterator--) {
	             result[result_iterator] =A[bottom][iterator];
	             result_iterator++;
	         }
	              dir=3;
	             bottom--;
	     
	     
	         for(iterator=bottom;iterator>=top;iterator--) {
	             result[result_iterator] =A[iterator][left];
	             result_iterator++;
	         }
	         dir=0;
	         left++;
	     
	 }
	 for(iterator = 0;iterator<length_of_array;iterator++) 
	 	printf("%d ",result[iterator]);
	 return 0;
}
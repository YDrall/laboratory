#include <stdio.h>

int findCount(const int* A, int n1, int B) {
    int low=0;
    int high=n1-1;
    int first_occur=-1;
    int last_occur=-1;
    int mid;
    //binary search to find any occurence of B
    while(low<=high) {
        // printf("low =%d, high = %d, mid = %d\n",low,high,(low+high)/2);
        mid = (low+high)/2;
        if(A[mid]==B) {
            first_occur = mid;
            high = mid-1;
        }
        else if(A[mid]>B) high =mid-1;
        else low=mid+1;
    }
    // printf("first occur = %d",first_occur);
    if(first_occur==-1) return 0;
    low=first_occur;
    high=n1-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(A[mid]==B) {
            last_occur = mid;
            low = mid+1;
        }
        else if(A[mid]>B) high =mid-1;
        else low=mid+1;
    }
    // printf(", last occur = %d\n",last_occur);
    return last_occur-first_occur+1;
}

int main() {
    int A[10] = {1,1,2,2,3,4,4,5,6,6};
    printf("%d\n",findCount(A,10,6));
    return 0;
}
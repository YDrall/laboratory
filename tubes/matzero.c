#include <stdio.h>

void setZeroes(int A[3][3], int n11, int n12) {
    int setx[n11];
    int sety[n12];
    int i,j;
    for(i=0;i<n11;i++) setx[i]=0;
    for(i=0;i<n12;i++) sety[i]=0;
    for(i=0;i<n11;i++) {
        for(j=0;j<n12;j++) {
            if(A[i][j]==0) {
                setx[i]=1;
                sety[j]=1;
            }
        }
    }
    for(i=0;i<n11;i++) {
        if(setx[i]==1) {
            printf("row: %d set to 0\n",i);
            for(j=0;j<n12;j++) A[i][j]=0;
        }
    }
    for(i=0;i<n12;i++) {
        if(sety[i]==1) {
            printf("col: %d set to 0\n",i);
            for(j=0;j<n11;j++) A[j][i]=0;
        }
    }
}

int main() {
    int A[3][3] = {
        {1,0,1},
        {1,1,1},
        {1,1,1}
    };
    setZeroes(A,3,3);
    
    return 0;
}
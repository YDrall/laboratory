#include <stdio.h>

int main() {
    int testcases;
    int len;
    int h[100];
    int i;

    scanf("%d",&testcases);
    while(testcases--) {
        scanf("%d",&len);
        for(i=0;i<len;i++) {
            scanf("%d",&h[i]);
        }
        if(len%2==0 || h[0]!=1) {
            printf("no\n");
        }
        else {
            
        }
    }
}
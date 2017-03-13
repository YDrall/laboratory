#include <stdio.h>
#include <stdlib.h>

int main() {
    int testcases;
    int rangefrom = 0;
    int rangeto = 0;
    int len=0;
    int i=0,j=0;
    int is_prime = -1;
    scanf("%d",&testcases);

    while(testcases--) {
        scanf("%d %d",&rangefrom,&rangeto);
        if(rangefrom<=2) {
            if(rangeto>=2)
                printf("2\n");
            rangefrom=3;
        } 
        if(rangefrom%2==0) rangefrom++;
        for(i=rangefrom;i<=rangeto;i+=2) {
            is_prime=1;
            for(j=3;j*j<=i;j+=2) {
                if(i%j==0) {
                    is_prime = 0;
                    break;
                }
            }
            if(is_prime==1) printf("%d\n",i);
        }
    }
    return 0;
}
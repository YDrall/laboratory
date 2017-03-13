#include <stdio.h>
#include <string.h>

int main() {
    int testcases;
    char input[1000000];
    char c;
    int len = 0;
    scanf("%d",&testcases);
    getchar(); // to skip \n after scanf
    while(testcases--) {
        len=0;
        while((c=getchar())!='\n') {
            input[len] = c;
            len +=1;
        }
        input[len]='\0';
        
    }
}
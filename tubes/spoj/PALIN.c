#include <stdio.h>
#include <string.h>

int main() {
    int testcases;
    char input[1000000];
    char c;
    int len = 0;
    int firstPointer;
    int secondPointer;
    scanf("%d",&testcases);
    getchar(); // to skip \n after scanf
    while(testcases--) {
        len=0;
        while((c=getchar())!='\n') {
            input[len] = c;
            len +=1;
        }
        input[len]='\0';
        input[0] = (char)((int)(input[0] - '0') -1);
        printf("%d\n",input[0]);
    }
}
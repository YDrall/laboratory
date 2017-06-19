#include <stdio.h>

#define HEAD 1
#define TAIL 2
#define NONE 0
#define INVALID -1
#define VALID 1

int main() {
    int testcases;
    int len;
    int prev;
    char c;
    int i;
    char input[501];
    int ans;
    scanf("%d",&testcases);
    while(testcases--) {
        scanf("%d",&len);
        scanf("%s",&input);
        prev = NONE;
        ans = VALID;
        for(i=0;i<len;i++) {
            c=input[i];
            if(c=='H') {
                ans = INVALID;
                if(prev==HEAD)
                    break;
                prev = HEAD;
            }
            if(c=='T') {
                if(prev==TAIL||prev==NONE) {
                    ans=INVALID;
                    break;
                }
                ans=VALID;
                prev=TAIL;
            }
        }
        if(ans==VALID)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;
}
#include <stdio.h>
#include <ctype.h>
/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
int isPalindrome(char* A) {
    int len=0;
    while(A[len]!='\0')
        len++;
    
    int i=0;
    int isPal=1;
    while(i<len) {
        if( ( (A[i]>='0' && A[i]<='9') || (tolower(A[i])<='z' && tolower(A[i])>='a') ) &&
        ( (A[len]>='0' && A[len]<='9')|| (tolower(A[len])<='z' && tolower(A[len])>='a') ) ) {
            if(tolower(A[i])!=tolower(A[len])) {
                printf("mismatch at %d %d and char is %c %c\n",i,len,A[i],A[len]);
                isPal = 0;
                break;
            }
            else {
                len--;
                i++;
            }
        }
            
        else if(tolower(A[i])>'z' || (tolower(A[i])<'a' && (A[i] >'9' || A[i]<'0') ))
            i++;
        else if(tolower(A[len])>'z' || (tolower(A[len])<'a' && (A[len] >'9' || A[len]<'0') ))
            len--;
    }
    
    return isPal;
    
}

int main() {
    char A[100] = "11aa11\0";
    printf("%d\n",isPalindrome(A));
    return 0;
}
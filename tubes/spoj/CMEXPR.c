#include <stdio.h>
#include <string.h>

#define PRIORITY_HIGH 1
#define PRIORITY_LOW -1
#define PRIORITY_EQUAL 0

int get_priority(char op1, char op2) {
    if((op1=='*' && op2=='/')|| (op1=='/' && op2=='*'))
        return PRIORITY_EQUAL;
    else if((op1=='*' || op1=='/') && (op2=='+' || op2=='-'))
        return PRIORITY_HIGH;
    else if((op2=='*' || op2=='/') && (op1=='+' || op1=='-'))
        return PRIORITY_LOW;
    else if(op1=='-' && op2=='+')
        return PRIORITY_HIGH;
    else return PRIORITY_EQUAL;
}

int is_operator(char op) {
    return op=='*' || op=='/' || op=='-' || op=='+';
}

int main() {
    int testcases;
    char expression[251];
    int length;
    int iterator;
    char stack[250];
    int stackp=0;
    scanf("%d",&testcases);
    
    while(testcases--) {
        scanf("%s",expression);
        length = strlen(expression);
        stackp =-1;
        for(iterator = 0;iterator<length;iterator++) {
            
            if(expression[iterator]=='(') {
                if(is_operator(experssion[iterator-1]) && is_operator(experssion[iterator+1]) && get_priority(experssion[iterator-1],expression[iterator+2])==)
                stack[stackp] = experssion[iterator];
            }
            else if(expression[iterator]==")") {
                if(stack!==-1 && stack[stackp]=="(")
                    stack[stackp] = experssion[iterator];
            }
        }
    }
    return 0;
}
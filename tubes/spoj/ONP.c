#include <stdio.h>

int an_alphabet(char ch) {
    return (ch -'a' >=0 ) && (ch -'a') <= 26;
}

int an_operator(char ch) {
    return ch == '*' || ch =='-' || ch =='+' || ch == '/' || ch == '^';
}

int a_closing_bracket(char ch) {
    return ch ==')';
}
void push(char *stack, int *stack_pointer, char ch) {
    *stack_pointer +=1;
    stack[*stack_pointer] = ch;
    // printf("%d",*stack_pointer);
}

void print_operator_if_any(char *stack, int *stack_pointer) {
    if(stack_pointer>=0) {
        printf("%c",stack[*stack_pointer]);
        *stack_pointer -=1;
        // printf("%d",*stack_pointer);
    }
}

void clear_stack(char *stack, int range) {
    int i;
    for(i=0;i<range;i++) 
        stack[i] = ' ';
}

int main() {
    char stack[400];
    int stack_pointer=-1;
    int testcases=0;
    scanf("%d",&testcases);
    int parse_index=0;
    char input[400];
    char curr_char;
    while(testcases--) {
        scanf("%s",input);
        stack_pointer =-1;
        parse_index=0;
        while(input[parse_index] != '\0') {
            curr_char = input[parse_index];
            
            if(an_alphabet(curr_char))
                printf("%c",curr_char);
            else if(an_operator(curr_char))
                push(stack,&stack_pointer,curr_char);
            else if(a_closing_bracket(curr_char))
                print_operator_if_any(stack,&stack_pointer);

            parse_index +=1;
        }
        printf("\n");
        // clear_stack(stack,parse_index);
    }
}
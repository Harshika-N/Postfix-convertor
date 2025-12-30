#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX]; // Stack to hold strings
int top = -1;

// Push a string onto stack
void push(char str[]) {
    strcpy(stack[++top], str);
}

// Pop a string from stack
void pop(char str[]) {
    strcpy(str, stack[top--]);
}

// Check if character is operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int main() {
    char prefix[MAX];
    char op1[MAX], op2[MAX], temp[MAX];
    
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    
    int len = strlen(prefix);
    
    // Traverse from right to left
    for (int i = len - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            pop(op1);
            pop(op2);
            sprintf(temp, "%s%s%c", op1, op2, prefix[i]); // Combine to postfix
            push(temp);
        } else {
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        }
    }
    
    printf("Postfix Expression: %s\n", stack[top]);
    
    return 0;
}

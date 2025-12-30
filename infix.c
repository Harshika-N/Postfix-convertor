#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

// Check precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    char infix[MAX], postfix[MAX];
    int k = 0;
    
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        
        if (isalnum(c)) { // Operand
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    
    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    
    postfix[k] = '\0';
    
    printf("Postfix Expression: %s\n", postfix);
    
    return 0;
}

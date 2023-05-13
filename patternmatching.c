#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

bool is_empty() {
    return top == -1;
}

bool is_full() {
    return top == MAX_SIZE - 1;
}

void push(char c) {
    if (is_full()) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (is_empty()) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

bool is_matching_pair(char left, char right) {
    if (left == '(' && right == ')') {
        return true;
    } else if (left == '{' && right == '}') {
        return true;
    } else if (left == '[' && right == ']') {
        return true;
    } else {
        return false;
    }
}

bool is_balanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (is_empty() || !is_matching_pair(pop(), exp[i])) {
                return false;
            }
        }
    }
    return is_empty();
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (is_balanced(exp)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }
    return 0;
}

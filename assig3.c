#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define a structure for the stack
struct Stack {
    char data[100]; // Assuming a maximum length for the input string
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char c) {
    stack->data[++stack->top] = c;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

// Function to check if parentheses are balanced
bool balancedParenthesis(char inputStr[]) {
    struct Stack stack;
    initialize(&stack);
    int len = strlen(inputStr);

    for (int i = 0; i < len; i++) {
        char current = inputStr[i];

        if (current == '{' || current == '[' || current == '(') {
            push(&stack, current);
        } else if (current == '}' || current == ']' || current == ')') {
            if (stack.top == -1) {
                return false;
            }

            char popChar = pop(&stack);

            if ((current == '}' && popChar != '{') ||
                (current == ']' && popChar != '[') ||
                (current == ')' && popChar != '(')) {
                return false;
            }
        }
    }

    return (stack.top == -1);
}

int main() {
    char inputStr[100];

    printf("Enter input expression ");
    fgets(inputStr, sizeof(inputStr), stdin);

    // Remove the newline character if it's present
    if (inputStr[strlen(inputStr) - 1] == '\n') {
        inputStr[strlen(inputStr) - 1] = '\0';
    }

    if (balancedParenthesis(inputStr)) {
        printf("Input expression %s is balanced.\n", inputStr);
    } else {
        printf("Input string %s is not balanced.\n", inputStr);
    }

    return 0;
}

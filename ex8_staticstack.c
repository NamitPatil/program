#include <stdio.h>

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow: Cannot push onto a full stack.\n");
        return;
    }

    stack->top++;
    stack->items[stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow: Cannot pop from an empty stack.\n");
        return -1;  // Return an arbitrary value to indicate an error
    }

    int poppedValue = stack->items[stack->top];
    stack->top--;
    return poppedValue;
}

void displayStack(struct Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d -> ", stack->items[i]);
    }
    printf("NULL\n");
}

int main() {
    struct Stack myStack;
    initializeStack(&myStack);

    int choice, value;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&myStack, value);
                break;
            case 2:
                value = pop(&myStack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                displayStack(&myStack);
                break;
            case 4:
                // Do nothing, just exit the loop
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
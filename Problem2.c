#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* stackTop = NULL;

int isStackEmpty() {
    return stackTop == NULL;
}

void showStack() {
    if (isStackEmpty()) {
        printf("The stack is currently empty.\n");
        return;
    }
    struct Node* current = stackTop;
    printf("Current stack elements:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void addToStack(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = item;
    newNode->next = stackTop;
    stackTop = newNode;
    printf("%d has been added to the stack.\n", item);
}

void removeFromStack() {
    if (isStackEmpty()) {
        printf("Error: Stack Underflow! Unable to remove an item.\n");
        return;
    }
    struct Node* temp = stackTop;
    printf("%d has been removed from the stack.\n", stackTop->data);
    stackTop = stackTop->next;
    free(temp);
}

int main() {
    int userChoice, item;

    do {
        printf("\nSelect an operation for the stack:\n");
        printf("1. Check if the stack is empty\n");
        printf("2. Show stack contents\n");
        printf("3. Add item to stack\n");
        printf("4. Remove item from stack\n");
        printf("5. Exit program\n");
        printf("Your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                if (isStackEmpty())
                    printf("The stack is empty.\n");
                else
                    printf("The stack contains items.\n");
                break;
            case 2:
                showStack();
                break;
            case 3:
                printf("Enter the item to add: ");
                scanf("%d", &item);
                addToStack(item);
                break;
            case 4:
                removeFromStack();
                break;
            case 5:
                printf("Program is terminating.\n");
                break;
            default:
                printf("Invalid option. Please select again.\n");
        }
    } while (userChoice != 5);

    return 0;
}
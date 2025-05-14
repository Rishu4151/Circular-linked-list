#include <stdio.h>
#define MAX_SIZE 100

int myStack[MAX_SIZE];
int stackTop = -1;
int isStackEmpty() 
{
    return stackTop == -1;
}
void showStack() 
{
    if (isStackEmpty()) 
    {
        printf("The stack is currently empty.\n");
        return;
    }
    printf("Current stack elements:\n");
    for (int i = stackTop; i >= 0; i--) 
    {
        printf("%d\n", myStack[i]);
    }
}
void addToStack(int item) 
{
    if (stackTop == MAX_SIZE - 1) 
    {
        printf("Error: Stack Overflow! Unable to add %d\n", item);
        return;
    }
    myStack[++stackTop] = item;
    printf("%d has been added to the stack.\n", item);
}
void removeFromStack() 
{
    if (isStackEmpty()) 
    {
        printf("Error: Stack Underflow! Unable to remove an item.\n");
        return;
    }
    printf("%d has been removed from the stack.\n", myStack[stackTop--]);
}
int main() 
{
    int userChoice, item;
    do 
    {
        printf("\nSelect an operation for the stack:\n");
        printf("1. Check if the stack is empty\n");
        printf("2. Show stack contents\n");
        printf("3. Add item to stack\n");
        printf("4. Remove item from stack\n");
        printf("5. Exit program\n");
        printf("Your choice: ");
        scanf("%d", &userChoice);
        switch (userChoice) 
        {
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
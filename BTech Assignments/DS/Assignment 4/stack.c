// Program to implement a stack using an array

#include <stdio.h>
#define SIZE 10

// functions for various operations on the stack
void push(int element);
void pop();
void peek();
void isEmpty();
void display();

int top = -1;
int stack[SIZE];

int main()
{
    int action = 0; // to choose
    int element;
    printf("Enter a value to operate the following on the stack: \n");
    printf("Push an element             : 1\n");
    printf("Pop an element              : 2\n");
    printf("See the top element         : 3\n");
    printf("Check whether empty         : 4\n");
    printf("Display stack               : 5\n");
    printf("To stop the program         : 0\n");
    printf("******************************************\n\n");
    
    do
    {
        scanf("%d", &action);

        switch(action)
        {
            case 0: 
                printf("Program is over!!!\n");
                break;

            case 1:
                printf("Enter the value to be pushed in the stack: ");
                scanf("%d", &element);
                push(element);
                printf("\nGo again!!!\n");
                break;
        
            case 2:
                pop();
                printf("\nGo again!!!\n");
                break;
        
            case 3:
                peek();
                printf("\nGo again!!!\n");
                break;
        
            case 4:
                isEmpty();
                printf("\nGo again!!!\n");
                break;
        
            case 5:
                display();
                printf("\nGo again!!!\n");
                break;

            default:
                printf("!!! Wrong selection !!!\n");
                printf("\nGo again!!!\n");
        }
    } while (action != 0);
    

    return 0;
}

void push(int element)
{
    if (top == SIZE - 1)
    {
        printf("Stack is FULL, no space to push!!!\n");
    }
    else 
    {
        top++;
        stack[top] = element;
        printf("Insertion of '%d' was successful.\n", element);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is EMPTY, no element to pop!!!\n");
    }
    else 
    {
        top--;
        printf("An element was removed from the stack.\n");
    }
}

void peek()
{
    if (top == -1)
    {
        printf("The stack is empty, no element to show!!!\n");
    }
    else
    {
        printf("Top element of the stack is '%d'\n", stack[top]);
    }
    
}

void isEmpty()
{
    if (top == -1)
    {
        printf("The stack is EMPTY!!!\n");
    }
    else
    {
        printf("The stack is NOT empty!!!\n");
    }
}

void display()
{
    if (top == -1)
    {
        printf("The stack is empty, no element to display!!!\n");
    }
    else
    {
        printf("The stack elements are :-> \n");
        for (int i = top; i > -1; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
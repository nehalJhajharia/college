// Program to implement a queue using an array

#include <stdio.h>
#define SIZE 10

// functions for various operations on queue
void enqueue(int element);
void dequeue();
void Front();
void display();

int front = -1, rear = -1;
int queue[SIZE];

int main()
{
    int action = 0; // to choose
    int element;
    printf("Enter a value to operate the following on the queue: \n");
    printf("Add an element                : 1\n");
    printf("Delete an element             : 2\n");
    printf("See the front element         : 3\n");
    printf("Display the queue             : 4\n");
    printf("To stop the program           : 0\n");
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
                printf("Enter the value to be added in the queue: ");
                scanf("%d", &element);
                enqueue(element);
                printf("\nGo again!!!\n");
                break;
        
            case 2:
                dequeue();
                printf("\nGo again!!!\n");
                break;
        
            case 3:
                Front();
                printf("\nGo again!!!\n");
                break;
        
            case 4:
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

void enqueue(int element)
{
    if (rear == SIZE-1)
    {
        printf("Queue is FULL, no space to add!!!\n");
    }
    else if (front == -1) // -> rear == -1
    {
        front = rear = 0;
        queue[rear] = element;
        printf("Insertion of '%d' was successful.\n", element);
    }
    else 
    {
        rear++;
        queue[rear] = element;
        printf("Insertion of '%d' was successful.\n", element);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is EMPTY, no element to remove!!!\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
        printf("An element was removed from the queue.\n");
    }
    else
    {
        front++;
        printf("An element was removed from the queue.\n");
    }
}

void Front()
{
    if (front == -1)
    {
        printf("Queue is EMPTY, no element to show!!!\n");
    }
    else
    {
        printf("Element on front of the queue is '%d'\n", queue[front]);
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is EMPTY, no element to show!!!\n");
    }
    else
    {
        printf("The elements of the queue are :->\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%4d  |", queue[i]);
        }
        printf("\n");
    }
}
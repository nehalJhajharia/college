#include <stdio.h>
#include <stdlib.h>

// creating a structure for linked list nodes
struct Node
{
    int data;
    struct Node *next;
};

// prototype functions
void Print(struct Node *HEAD);
void Insert(struct Node **headRef, int DATA);
int Count(struct Node *HEAD);
int oddCount(struct Node *HEAD);
int evenCount(struct Node *HEAD);
void Sum(struct Node **headRef);
void Median(struct Node *HEAD);

// MAIN function
int main()
{
    struct Node *head = NULL;

    Insert(&head, 1);
    Insert(&head, 3);
    Insert(&head, 5);
    Insert(&head, 2);
    Insert(&head, 4);
    Insert(&head, 6);
    
    printf("\nList : ");
    Print(head);
    printf("\n\n");

    Median(head);
    printf("\n\n");

    Sum(&head);
    printf("New list : ");
    Print(head);
    printf("\n\n");

    int count = Count(head);
    printf("Number of nodes : %d\n", count);

    count = oddCount(head);
    printf("Number of nodes with odd data : %d\n", count);

    count = evenCount(head);
    printf("Number of nodes with even data : %d\n\n", count);

    return 0;
}

// function to print a linked list
void Print(struct Node *HEAD)
{
    struct Node *temp = HEAD;
    while (temp != NULL)
    {
        printf("%3d", temp->data);
        temp = temp->next;
    }
}

// Insert a node at beginning
void Insert(struct Node **headRef, int DATA)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = DATA;
    newNode->next = *headRef;

    *headRef = newNode;
}

// Insert sum at last
void Sum(struct Node **headRef)
{
    int sum = 0;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = sum;
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    struct Node *temp = *headRef;
    sum = temp->data;
    while (temp->next != NULL)
    {
        temp = temp->next;
        sum += temp->data;
    }

    newNode->data = sum;
    temp->next = newNode;
}

// Count number of nodes
int Count(struct Node *HEAD)
{
    if (HEAD == NULL)
        return 0;

    int count = 0;
    struct Node *temp = HEAD;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

// Count number of nodes with odd data
int oddCount(struct Node *HEAD)
{
    if (HEAD == NULL)
        return 0;

    int count = 0;
    struct Node *temp = HEAD;

    while (temp != NULL)
    {
        if (temp->data % 2 == 1)
            count++;

        temp = temp->next;
    }

    return count;
}

// Count number of nodes with even data
int evenCount(struct Node *HEAD)
{
    if (HEAD == NULL)
        return 0;

    int count = 0;
    struct Node *temp = HEAD;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            count++;

        temp = temp->next;
    }

    return count;
}

// Get median
void Median(struct Node *HEAD)
{
    if (HEAD == NULL)
        printf("List is Empty!!");

    int N = Count(HEAD);
    struct Node *temp = HEAD;
    float median = 0;

    for (int i = 1; i < N/2; i++)
    {
        temp = temp->next;
    }

    if (N % 2 == 0)
    {
        median = temp->data;
        temp = temp->next;
        median = (median + temp->data) / 2;
    }
    else 
    {
        temp = temp->next;
        median = temp->data;
    }
    
    printf("Median : %.1f", median);
}

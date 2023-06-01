// DOUBLY Linked List

#include <stdlib.h>
#include <stdio.h>

struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Prototype functions
struct Node *getNewNode(int DATA);
void Insert(struct Node **headRef, int position, int DATA);
void Delete(struct Node **headRef, int position);
void Print(struct Node *HEAD);
void Search(struct Node *HEAD, int key);
void Max(struct Node *HEAD);
void Min(struct Node *HEAD);

// MAIN
int main()
{
    struct Node *head = NULL;

    Max(head);
    Min(head);

    Insert(&head, 0, 5);
    Insert(&head, 1, 7);
    Insert(&head, 0, 3);
    Insert(&head, 2, 8);
    Insert(&head, 1, 1);
    Insert(&head, 3, 9);
    Insert(&head, 9, 6);
    Insert(&head, 0, 0);
    Insert(&head, 46, 15);

    printf("\nList : ");
    Print(head);
    printf("\n");

    Delete(&head, 6);

    printf("\nList : ");
    Print(head);
    printf("\n");

    Delete(&head, 6);

    Search(head, 0);
    Search(head, 3);
    Search(head, 7);
    Search(head, 8);

    Max(head);
    Min(head);

    printf("\n");
    return 0;
}

// Get a new node
struct Node *getNewNode(int DATA)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = DATA;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert a node
void Insert(struct Node **headRef, int position, int DATA)
{
    if (position < 0)
    {
        printf("\nInvalid position!!\n");
        printf("%d was not inserted.\n", DATA);
        return;
    }

    struct Node *newNode = getNewNode(DATA);

    // If list is empty (head == NULL)
    if (*headRef == NULL)
    {
        *headRef = newNode;

        return;
    }

    struct Node *temp = *headRef;

    for (int i = 0; i < position-1; i++)
    {
        if (temp->next == NULL)
        {
            printf("\nInvalid position!!\n");
            printf("%d was not inserted.\n", DATA);
            return;
        }

        temp = temp->next;
    }
    
    if (position == 0)
    {
        newNode->next = temp;
        temp->prev = newNode;
        *headRef = newNode;
        return;
    }
    
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    temp = temp->next;
    temp = temp->next;
    if (temp != NULL)
        temp->prev = newNode;
}

// Delete a node
void Delete(struct Node **headRef, int position)
{
    if (position < 0)
    {
        printf("\nInvalid position!!\n");
        printf("No element was deleted.\n");
        return;
    }

    struct Node *current = *headRef;
    if (position == 0)
    {
        *headRef = current->next;
        free(current);
        return;
    }

    for (int i = 0; i < position; i++)
    {
        if (current->next == NULL)
        {
            printf("\nInvalid position!!\n");
            printf("No element was deleted.\n");
            return;
        }
        current = current->next;
    }

    struct Node *behind = current->prev;
    behind->next = current->next;
    if (current->next != NULL)
    {
        behind = behind->next;
        behind->prev = current->prev;
    }
    free(current);
}

// Print the list
void Print(struct Node *HEAD)
{
    struct Node *temp = HEAD;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Search an element
void Search(struct Node *HEAD, int key)
{
    struct Node *temp = HEAD;
    int position = 0;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("\n%d is at position '%d' in the list.\n", key, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    // key doesn't exist in the list
    printf("\n%d does not exist in the list!!\n", key);
}

// Find maximum element
void Max(struct Node *HEAD)
{
    if (HEAD == NULL)
    {
        printf("\nMaximum element cannot be found as list is empty!!\n");
        return;
    }

    struct Node *temp = HEAD;
    int max = temp->data;
    
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->data > max)
            max = temp->data;
    }

    printf("\nMaximum element is '%d'.\n", max);
}

// Find minimum element
void Min(struct Node *HEAD)
{
    if (HEAD == NULL)
    {
        printf("\nMinimum element cannot be found as list is empty!!\n");
        return;
    }

    struct Node *temp = HEAD;
    int min = temp->data;
    
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->data < min)
            min = temp->data;
    }

    printf("\nMinimum element is '%d'.\n", min);
}

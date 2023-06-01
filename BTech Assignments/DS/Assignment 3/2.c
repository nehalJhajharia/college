#include <stdio.h>
#include <stdlib.h>

void insert(int array[]);
void delete(int array[]);
void update(int array[]);
void moreThan(int array[]);
void printArray(int array[], int n);
void copyArray(int array[], int copyArray[], int n);

int main()
{
    int AUTO[31];
    int AUTOcopy[31];

    // filling AUTO with random values between 250 & 350
    for (int i = 0; i < 30; i++)
    {
        AUTO[i] = 250 + rand()%100;
    }

    // copying elements of AUTO to AUTOcopy
    copyArray(AUTO, AUTOcopy, 31);

    // printing AUTO
    printf("\nThe array AUTO is : \n");
    printArray(AUTOcopy, 30);
    
    // inserting an element
    insert(AUTO);
    copyArray(AUTOcopy, AUTO, 31);

    //deleting an element
    delete(AUTO);
    copyArray(AUTOcopy, AUTO, 31);

    // updating value at an index
    update(AUTO);
    copyArray(AUTOcopy, AUTO, 31);

    moreThan(AUTO);
}

void insert(int array[])
{
    int p;
    do
    {
        printf("\nWhere to insert: ");
        scanf("%d", &p);
    }while ((p < 0) || (p >= 30));

    for (int i = 30; i > p ; i--)
    {
        array[i] = array[i-1];
    }

    printf("Enter the value to be inserted: ");
    scanf("%d", &array[p]);

    printf("\nNew array after insertion is : \n");
    printArray(array, 31);
    
}

void delete(int array[])
{
    int p;
    do
    {
        printf("\nWhich to delete: ");
        scanf("%d", &p);
    }while ((p < 0) || (p >= 30));

    for (int i = p; i < 29; i++)
    {
        array[i] = array[i+1];
    }
    array[29] = 0;

    printf("\nNew array after deletion is : \n");
    printArray(array, 30);
}

void update(int array[])
{
    int p;
    do
    {
        printf("\nWhich to update: ");
        scanf("%d", &p);
    }while ((p < 0) || (p >= 30));

    printf("Enter the new value: ");
    scanf("%d", &array[p]);

    printf("\nNew array after update is : \n");
    printArray(array, 30);
}

void moreThan(int array[])
{
    printf("\nIndices for which more than 300 vehicles were sold: \n");
    for (int i = 0; i < 30; i++)
    {
        if (array[i] > 300)
        {
            printf("%d\n", i);
        }
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d -> %3d\n", i, array[i]);
    }
}

void copyArray(int array[], int copyArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        copyArray[i] = array[i];
    }
}
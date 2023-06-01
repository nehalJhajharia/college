// program to merge two arrays

#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size);
void sortArray(int array[], int size);

int main()
{
    int n1, n2;

    // taking the sizes of the arrays
    printf("Enter size of first arary: ");
    scanf("%d", &n1);
    printf("Enter size of second array: ");
    scanf("%d", &n2);

    int array1[n1];
    int array2[n2];

    // filling the random values in the arrays
    for (int i = 0; i < n1; i++)
    {
        array1[i] = rand()%100;
    }
    for (int i = 0; i < n2; i++)
    {
        array2[i] = rand()%100;
    }

    // sorting the arrays
    sortArray(array1, n1);
    sortArray(array2, n2);

    // printing the arrays
    printf("\nArray1 is : \n");
    printArray(array1, n1);
    printf("\nArray2 is : \n");
    printArray(array2, n2);

    // merging the 2 arrays
    int n = n1 + n2;
    int arrayMerge[n];
    for (int i = 0; i < n1; i++)
    {
        arrayMerge[i] = array1[i];
    }
    for (int i = n1; i < n; i++)
    {
        arrayMerge[i] = array2[i-n1];
    }

    // sorting the merged array
    sortArray(arrayMerge, n);

    // printing the merged array
    printf("\nThe merged array is : \n");
    printArray(arrayMerge, n);

    return 0;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%3d -> %4d\n", i, array[i]);
    }
    printf("\n");
}

void sortArray(int array[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if (array[j] < array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
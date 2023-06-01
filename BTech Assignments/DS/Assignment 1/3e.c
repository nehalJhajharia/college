// program to separate negative and positive integers in array
// 0 is included in positive numbers

#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size);

int main()
{
    int n;

    // taking the size of the array
    printf("Enter size of the arary: ");
    scanf("%d", &n);

    int array[n];

    // filling the random values in the array
    for (int i = 0; i < n; i++)
    {
        array[i] = rand()%100 - 50;
    }

    // printing the array
    printArray(array, n);

    // separating positive and negative values
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (array[j] >= 0)
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // printing the new array after separation
    printf("\nNew array is:\n");
    printArray(array, n);

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
// program to print all unique elements in an array
// unique elements are 1,2,3 for 1, 2, 2, 3, 3

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
        array[i] = rand()%10;
    }

    // printing the array
    printf("The array is : \n");
    printArray(array, n);

    // printing only the unique elements
    printf("The unique elements in the above array are: \n");
    for (int i = 0; i < n; i++)
    {
        int check = 0;
        for (int j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                check++;
                break;
            }
        }

        if (check == 0)
        {
            printf("%3d\n", array[i]);
        }
    }

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
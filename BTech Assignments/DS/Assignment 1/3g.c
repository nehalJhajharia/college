// program to find a pair in two arrays
// sum of the pair is closest to 'x'

#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size);
void sortArray(int array[], int size);

int main()
{
    int n1, n2, x;

    // taking x as input
    printf("Enter x : ");
    scanf("%d", &x);

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
    printArray(array1, n1);
    printArray(array2, n2);

    int sum = 1000;
    int p1 = 0;
    int p2 = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            int condition = array1[i] + array2[j] - x;
            if (condition < 0)
            {
                condition *= (-1);
            }

            if (condition < sum)
            {
                sum = condition;
                p1 = i;
                p2 = j;
            }
        }
    }

    printf("array1[%d] + array2[%d] is closest to %d.\n", p1, p2, x);
    printf("That is %d + %d is closest to %d\n", array1[p1], array2[p2], x);

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
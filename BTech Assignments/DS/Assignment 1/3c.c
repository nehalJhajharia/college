// program to separate odd and even integers in separate arrays

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
        array[i] = rand()%100;
    }

    // printing the array
    printArray(array, n);

    // separating odd and even in new arrays
    int even[n];
    int odd[n];
    int e = 0;
    int o = 0;

    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            even[e] = array[i];
            e++;
        }
        else 
        {
            odd[o] = array[i];
            o++;
        }
    }

    // printing the arrays
    printf("Even array is : \n");
    printArray(even, e);
    printf("Odd array is : \n");
    printArray(odd, o);

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
// Program to create Fibonacci series of length 10
// In this series, next element will be the sum of previous two numbers

#include <stdio.h>

int main()
{
    // Creating an array of size 10
    int array[10];

    // Assigning values to the first to indices as 0 and 1
    array[0] = 0;
    array[1] = 1;

    // Loop to assign values to the indices from 2 to 9
    for (int i = 2; i < 10; i++) {
        array[i] = array[i-1] + array[i-2];
    }


    // Printing the array, or as stated, the Fibonacci series
    for (int i = 0; i < 10; i++) {
        printf(" %d ", array[i]);
    }
    printf("\n");

    return 0;
}
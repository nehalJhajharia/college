#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int myArray[n];

    int ins;
    loop: // Loop to ensure the validity of the index
    printf("(Remember: index >= 0 and < %d) \n", n);
    printf("Enter the index of the element of the array to be inserted: ");
    scanf("%d", &ins);
    if (ins < 0 || ins >= n) {
        goto loop;
    }

    // Inserting the element
    printf("Enter the element: ");
    scanf("%d", &myArray[ins]);
    
    printf("\n"); // Taking a line-break

    return 0;
}
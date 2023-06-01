#include <stdio.h>

int main()
{
    int n1 = 0, n2;

    while (n1 <= 0) { //Loop to check if n1 is positive
        printf("Enter a POSITIVE number: ");
        scanf("%d", &n1);
    }
    
    do { //loop to check if n2 is less than n1 but greater than 0
        printf("Enter a POSITIVE number LESS than %d: ", n1);
        scanf("%d", &n2);
    } while ((n2 >= n1) || (n2 <= 0));
    

    //Printing even numbers between n1 and n2
    printf("Even numbers between %d and %d are: \n", n2, n1);
    int count = 0;
    for (int i = n2+1; i < n1; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal number of even numbers between %d and %d = %d \n", n2, n1, count);

    return 0;
}
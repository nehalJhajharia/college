#include <stdio.h>

int flip(int num, int N);

int main()
{
    // Taking input from the user
    int num, N;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the number of digits to be flipped: ");
    scanf("%d", &N);

    // Flipping the last N digits of the number
    num = flip(num, N);

    printf("%d\n", num);

    return 0;
}

// Function to flip
int flip(int num, int N) 
{
    int remainder, ten = 1;
    for (int i = 0; i < N; i++) {
        remainder *= 10;
        remainder += num % 10;
        num /= 10;
        ten *= 10;
    }

    num *= ten;
    num += remainder;

    return num;
}
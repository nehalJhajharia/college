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
    
    // Checking the condition
    int check = flip((flip(num, N)), N);

    printf("%d\n", check);

    return 0;
}

// Funtion to flip
int flip(int num, int N) 
{
    int initial_num = num;

    int remainder = 0, ten = 1;
    for (int i = 0; i < N; i++) {
        remainder *= 10;
        remainder += num % 10;
        num /= 10;
        ten *= 10;
        i++;
    }

    num *= ten;
    num += remainder;

    return num;
}
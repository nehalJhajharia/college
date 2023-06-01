#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int initial_num = num;
    int digit;
    int result = 0;
    while (num > 0) {
        digit = num % 10;
        num /= 10;
        result += (digit * digit);
    }

    printf("Sum of squares of each digit of %d = %d \n", initial_num, result);

    return 0;
}
#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num1);
    printf("Enter another 4-digit number: ");
    scanf("%d", &num2);
    
    printf("Sum of corresponding digits of %d and %d multiplied = ", num1, num2);

    int result = 0;
    for (int i = 0; i < 4; i++) {
        result += ((num1%10) * (num2%10));
        num1 /= 10;
        num2 /= 10;
    }

    printf("%d \n", result);

    return 0;
}
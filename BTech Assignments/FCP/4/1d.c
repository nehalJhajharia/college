#include <stdio.h>
#include <math.h>

int main() {
    int num, x = 0, result = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    int initial_num = num;
    while (num > 0)
    {
        x = num % 10;
        num /= 10;
        result += x * x * x;
    }

    if (result == initial_num) {
        printf("%d is an Armstrong number.", initial_num);
    }
    else {
        printf("%d is NOT an armstrong number.", initial_num);
    }

    return 0;
}
#include <stdio.h>
#include <math.h>

int factorial(int x) {
    int p = 1;
    for (int i = x; i > 1; i--) {
        p *= i;
    }

    return p;
}

int main() {
    int num, x = 0, result = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    int initial_num = num;
    while (num > 0)
    {
        x = num % 10;
        num /= 10;
        result += factorial(x);
    }

    if (result == initial_num) {
        printf("%d is a Strong number.", initial_num);
    }
    else {
        printf("%d is NOT a strong number.", initial_num);
    }

    return 0;
}
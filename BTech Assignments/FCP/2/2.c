//Simple Calculator

#include <stdio.h>

int main()
{
    float a, b, result;
    char oper;
    printf("For the expression, \"a oper b\" \n");
    printf("a = ");
    scanf("%f", &a);
    printf("Choose 'oper' from '+', '-', '*', '/' to enter.\n");
    printf("oper = ");
    scanf(" %c", &oper);
    printf("b = ");
    scanf("%f", &b);

    switch(oper)
    {
        case '+' :
            result = a + b;
            printf("%.2f + %.2f = %.2f\n", a, b, result);
            break;
        case '-' :
            result = a - b;
            printf("%.2f - %.2f = %.2f\n", a, b, result);
            break;
        case '*' :
            result = a * b;
            printf("%.2f * %.2f = %.2f\n", a, b, result);
            break;
        case '/' :
            result = a / b;
            printf("%.2f / %.2f = %.2f\n", a, b, result);
            break;
        default :
            printf("Please choose a valid operation.\n");
    }

    return 0;
}
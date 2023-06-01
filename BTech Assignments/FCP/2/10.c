//Program to convert inches into centimeters.

#include <stdio.h>

int main()
{
    float inch;
    printf("Enter value in inches: ");
    scanf("%f", &inch);

    printf("%.2f\" = %.2fcm\n", inch , 2.54 * inch);

    return 0;
}
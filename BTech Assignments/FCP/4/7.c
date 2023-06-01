#include <stdio.h>

int main()
{
    int A, B, C;

    printf("Enter A: ");
    scanf("%d", &A);
    printf("Enter B: ");
    scanf("%d", &B);
    printf("Enter B: ");
    scanf("%d", &C);
    
    int count = 0;
    for (int a = 1; a <= A; a++) {
        for (int b = 1; b <= B; b++) {
            for (int c = 1; c <= C; c++) {
                if (a*c > b*b) {
                    count++;
                }
            }
        }
    }

    printf("Number of triples (A, B, C) = %d \n", count);

    return 0;
}
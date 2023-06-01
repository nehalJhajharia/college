#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int j = 1;
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        int k = j;
        for (k = j; k <= (2*n)-j+2; k++) {
            printf(" ");
        }
        for (int j = k; j <= (2*n)+1 ; j++) {
            printf("%d", (2*n)-j+2);
        }
        printf("\n");
    }

    return 0;
}
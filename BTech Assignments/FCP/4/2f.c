#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) { //loop for upper triangle
        for (int j = 0; j < n-i; j++) {
            printf("  ");
        }
        int p = 0;
        for (int j = 1; j <= 2*i - 1; j++) {
            printf("%c ", j+64+p);
            p++;
        }
        printf("\n");
    }
    for (int i = n-1; i >= 1; i--) {  //loop for lower triangle
        for (int j = 0; j < n-i; j++) {
            printf("  ");
        }
        int p = 0;
        for (int j = 1; j <= 2*i - 1; j++) {
            printf("%c ", j+64+p);
            p++;
        }
        printf("\n");
    }

    return 0;
}
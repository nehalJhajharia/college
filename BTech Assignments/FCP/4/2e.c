#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", j+1);
        }
        printf("\n");
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            printf("%d ", j+1);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int L, R;

    printf("Enter the smaller integer number: ");
    scanf("%d", &L);
    printf("Enter the larger integer number: ");
    scanf("%d", &R);

    if (R < L) {  // if R < L, it swaps their values
        int intermediate = R;
        R = L;
        L = intermediate;
    }

    int check = 0;
    int K;
    for (int i = R; i >= L; i--) {
        int product = (L-i) * (i-R);
        if (product > check) {
            check = product;
            K = i;
        }
    }

    printf("K = %d \n", K);

    return 0;
}
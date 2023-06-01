#include <stdio.h>
#include <math.h>

int main() {
    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    printf("The series results: %f \n", sin(x));

    return 0;
}
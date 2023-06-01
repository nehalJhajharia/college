/* Program to show equivalent grade */

#include <stdio.h>

int main() 
{
    int marks;
    printf("Enter your marks out of 100: ");
    scanf("%d", &marks);

    if(marks < 35) {
        printf("Fail\n");
    }
    else if(marks < 60) {
        printf("Second Class\n");
    }
    else if(marks < 80) {
        printf("First Class\n");
    }
    else {
        printf("Distinction\n");
    }

    return 0;
}
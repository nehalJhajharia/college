#include <stdio.h>

struct book {  // Defining the structure for book
    long int ISBN;
    char title[100];
    float price;
};

int main() 
{
    struct book book1;
    struct book book1[10];

    printf("ISBN: ");  
    scanf("%ld", &book1.ISBN); // taking input of 13-digit ISBN number

    printf("Title: ");  
    scanf("%s", book1.title); // taking input of title

    printf("Price (in Rupees): ");
    scanf("%f", &book1.price); // taking input of price

    // printing the values
    printf("Details of the book are as below: \n");
    printf("ISBN : %ld \nTitle : %s\nPrice : %.2f rupees\n",
        book1.ISBN,
        book1.title,
        book1.price);

    return 0;
}
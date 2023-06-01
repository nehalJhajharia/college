#include <stdio.h>

struct item { // Defining a structure for an item
    char item_name[20];
    int quantity;
    float price;
    float amount;
};

float total_amount(struct item item1); // Declaration of function

int main() 
{
    struct item item1;

    printf("For the item, enter the following: \n");

    printf("Name: ");
    scanf("%s", item1.item_name); // take name

    printf("Quantity: ");
    scanf("%d", &item1.quantity); // take quantity

    printf("Price of 1 unit: ");
    scanf("%f", &item1.price); // take price of 1 unit

    item1.amount = total_amount(item1); // calculate amount

    // Printing the information
    printf("\n\n\nYour item's information is provided below: \n");

    printf("\nName : %s \nQuantity : %d \nPrice of 1 unit : %.2f \nAmount : %.2f\n",
        item1.item_name,
        item1.quantity,
        item1.price,
        item1.amount);

    return 0;
}

// Function to calculate amount
float total_amount(struct item item1) {
    struct item;
    item1.amount = item1.quantity * item1.price;

    return item1.amount;
}
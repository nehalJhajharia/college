#include <stdio.h>

int main() 
{
    float mill_amount, loom_amount, purchase_amount, x, y;
    printf("Purchase amount of Mill Cloth: ");
    scanf("%f", &mill_amount);
    printf("Purchase amount of Handloom Items: ");
    scanf("%f", &loom_amount);

    purchase_amount = mill_amount + loom_amount;
    
    if (purchase_amount > 300) {
        x = 0.90;
        y = 0.85;
    }
    else if (purchase_amount > 200) {
        x = 0.925;
        y = 0.90;
    }
    else if (purchase_amount > 100) {
        x = 0.95;
        y = 0.925;
    }
    else {
        x = 1;
        y = 0.95;
    }

    mill_amount *= x; 
    loom_amount *= y;
    
    purchase_amount = mill_amount + loom_amount;

    printf("Amount to be paid by the customer: %f \n", purchase_amount);

    return 0;
}
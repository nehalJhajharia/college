#include <stdio.h>

int main() 
{
    float policy_amount, commission;
    printf("Enter the Policy Amount: ");
    scanf("%f", &policy_amount);

    if (policy_amount <= 10000) {
        commission = 0.005 * policy_amount;
    }
    else if (policy_amount < 25000) {
        policy_amount = policy_amount - 10000;
        commission = 50 + (0.006 * policy_amount);
    }
    else {
        policy_amount = policy_amount - 25000;
        commission = 140 + (0.0075 * policy_amount);
    }

    printf("Commission earned by the sames woman: %f \n", commission);

    return 0;
}
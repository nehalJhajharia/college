// C header file to perform division on binary numbers
// The division is done by cumulative subtraction

#include "array_to_num.h"

int division_unsigned_binary_numbers_U20CS093(unsigned int b1, unsigned int b2)
{
    if (b1 == b2)       // Incase numbers are equal
    {
        return 1;
    }
    else if (b1 < b2)   // Incase, divisor > dividend
    {
        return 0;
    }

    // else b1 > b2

    int quot = 0;

    // Define temporary variables and arrays to contain b1 & b2
    int arr1[11] = {0};
    int arr2[11] = {0};
    unsigned int temp1 = b1;
    unsigned int temp2 = b2;

    // Fill the elements of b1 and b2 in arrays
    int i = 1;
    while (temp1 > 0)
    {
        arr1[11-i] = temp1 % 10;
        temp1 /= 10;
        i++;
    }
    int j = 1;
    while (temp2 > 0)
    {
        arr2[11-j] = temp2 % 10;
        temp2 /= 10;
        j++;
    }

    // Perform cumulative subtraction until b1 gets less than b2
    while (b1 >= b2)
    {
        for (int t = 0; t < j-1; t++)
        {
            // both arr1[10-t] & arr2[10-t] are either 1 or 0
            if (arr1[10-t] == arr2[10-t])
            {
                arr1[10-t] = 0;
            }

            // arr1[10-t] = 1 && arr2[10-t] = 0
            else if (arr1[10-t] > arr2[10-t])
            {
                arr1[10-t] = 1;
            }

            // arr1[10-t] = 0 && arr2[10-t] = 1
            else 
            {
                arr1[10-t] = 1;
                int p = 1;

                // while loop to get the carry
                while (arr1[10-t-p] != 1)
                {
                    arr1[10-t-p] = 1;
                    p++;
                }

                arr1[10-t-p] = 0;
            }
        }

        // Increment quot by 1
        quot++;

        // Convert b1 back to num
        // Assign new value to b1
        b1 = array_to_num(arr1);
    }

    // Return the quotient
    return quot;
}
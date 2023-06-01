// Program to display the following
//           1
//         1   1
//       1   2   1
//     1   3   3   1
//   1   4   6   4   1
// 1   5   10  10   5  1

#include <stdio.h>

int main() 
{
   int coeff = 1, space, i, j;
   for (i = 0; i < 6; i++) {
      for (space = 1; space <= 6 - i; space++)
         printf("    ");
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            coeff = 1;
         else
            coeff = coeff * (i - j + 1) / j;
         printf("%8d", coeff);
      }
      printf("\n");
      printf("space = %d\n", space);
      printf("i = %d\n", i);
      printf("j = %d\n", j);
   }
   return 0;
}
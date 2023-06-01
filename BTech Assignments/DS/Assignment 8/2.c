// Binary search implementation on unsorted array
// Unsorted array is first sorted

#include <stdio.h>
#include "Functions2.h"

// MAIN
int main()
{
   // Size of array
   int N = 0;
   Size(&N);

   // Generate array
   int array[N];
   Generate(array, N);

   // Sort array (Ascending Order)
   sort(array, N);

   // Print array
   Print(array, N);

   // Input Key
   int key = 0;
   Key(&key);
   binarySearch(array, N, key);

   return 0;
}
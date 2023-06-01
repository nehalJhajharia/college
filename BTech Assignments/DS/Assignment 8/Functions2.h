// Header file to contain user-defined functions
// For 2.c

// Get size of array
void Size(int *SIZE)
{
   printf("Enter size of the array : ");
   scanf("%d", SIZE);
}

// Generate array
void Generate(int ARRAY[], int SIZE)
{
   for (int i = 0; i < SIZE; i++)
   {
      printf("array[%d] : ", i);
      scanf("%d", &ARRAY[i]);
   }
}

// Sort array in Ascending order
void sort(int ARRAY[], int SIZE)
{
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE-i; j++)
      {
         if (ARRAY[j] > ARRAY[j+1])
         {
            int temp = ARRAY[j+1];
            ARRAY[j+1] = ARRAY[j];
            ARRAY[j] = temp;
         }
      }
   }
}

// Print array
void Print(int ARRAY[], int SIZE)
{
   printf("\n");
   for (int i = 0; i < SIZE; i++)
   {
      printf("%d | ", ARRAY[i]);
   }
   printf("\n\n");
}

// Get key
void Key(int *KEY)
{
   printf("Enter element to be searched : ");
   scanf(" %d", KEY);
}

// Binary Search
void binarySearch(int ARRAY[], int N, int key)
{
   int n = (N/2);
   int t = n;
   int count = 0;

   while (n >= 0 && n < N)
   {
      t++;
      t /= 2;
      if (t == 1) 
         count++;
      if (count > 3) 
         break;

      if (ARRAY[n] == key)
      {
         printf("%d is array[%d].\n", key, n);
         return;
      }
      if (ARRAY[n] > key)
         n -= t;
      if (ARRAY[n] < key)
         n += t;
   }

   printf("%d does not exist in the array.\n", key);
}

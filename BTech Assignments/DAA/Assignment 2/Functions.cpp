// Header file to store functions

// Take input in array
void Input(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cin >> array[i];
}

// PRINT ARRAY
void PrintArray(int array[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " | ";

    cout << endl << endl;
}

// Reverse Sort Array
void ReverseSort(int arr[], int size)
{
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[j-1] < arr[j])
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Insertion Sort
void InsertionSort(int arr[], int size)
{
    int key = 0;
    int i = 0;
    int j = 0;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

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

// Copy array to another
void CopyArray(int arr1[], int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr1[i] = arr[i];
}

// LINEAR SEARCH
void LinearSearch(int array[], int size, int key)
{
    for(int i = 0; i < size; i++)
        if (key == array[i])
            return;
}

// BUBBLE SORT
void BubbleSort(int array[], int size)
{
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (array[j-1] > array[j])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

// SELECTION SORT
void SelectionSort(int array[], int size)
{
    int min = 0;
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i; j < size; j++)
            if (array[j] < array[min])
                min = j;

        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

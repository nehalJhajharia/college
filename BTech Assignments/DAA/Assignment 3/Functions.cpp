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

    cout << endl
         << endl;
}

// Reverse Sort Array
void ReverseSort(int garr[], int farr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        farr[i] = garr[size-i-1];
    }
}

// Merge
void Merge(int arr[], int const left, int const mid, int const right)
{
    auto const lsize = mid - left + 1;
    auto const rsize = right - mid;

    auto *leftArray = new int[lsize];
    auto *rightArray = new int[rsize];

    for (auto i = 0; i < lsize; i++)
    {
        leftArray[i] = arr[left + i];
    }
    for (auto i = 0; i < rsize; i++)
    {
        rightArray[i] = arr[mid + 1 + i];
    }

    auto li = 0;
    auto ri = 0;
    int mergedi = left;

    while (li < lsize && ri < rsize)
    {
        if (leftArray[li] <= rightArray[ri])
        {
            arr[mergedi] = leftArray[li];
            li++;
        }
        else
        {
            arr[mergedi] = rightArray[ri];
            ri++;
        }
        mergedi++;
    }

    while (li < lsize)
    {
        arr[mergedi] = leftArray[li];
        li++;
        mergedi++;
    }

    while (ri < rsize)
    {
        arr[mergedi] = rightArray[ri];
        ri++;
        mergedi++;
    }
}

// Merge Sort
void MergeSort(int arr[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, begin, mid, end);
}

// Three way Merge Sort
// Merge
void Merge3(int gArray[], int low, int mid1,
            int mid2, int high, int destArray[])
{
    int i = low, j = mid1, k = mid2, l = low;

    // choose smaller of the smallest in the three ranges
    while ((i < mid1) && (j < mid2) && (k < high))
    {
        if (gArray[i] < gArray[j])
        {
            if (gArray[i] < gArray[k])
            {
                destArray[l++] = gArray[i++];
            }
            else
            {
                destArray[l++] = gArray[k++];
            }
        }
        else
        {
            if (gArray[j] < gArray[k])
            {
                destArray[l++] = gArray[j++];
            }
            else
            {
                destArray[l++] = gArray[k++];
            }
        }
    }

    // case where first and second ranges
    // have remaining values
    while ((i < mid1) && (j < mid2))
    {
        if (gArray[i] < gArray[j])
        {
            destArray[l++] = gArray[i++];
        }
        else
        {
            destArray[l++] = gArray[j++];
        }
    }

    // case where second and third ranges
    // have remaining values
    while ((j < mid2) && (k < high))
    {
        if (gArray[j] < gArray[k])
        {
            destArray[l++] = gArray[j++];
        }
        else
        {
            destArray[l++] = gArray[k++];
        }
    }

    // case where first and third ranges have
    // remaining values
    while ((i < mid1) && (k < high))
    {
        if (gArray[i] < gArray[k])
        {
            destArray[l++] = gArray[i++];
        }
        else
        {
            destArray[l++] = gArray[k++];
        }
    }

    // copy remaining values from the first range
    while (i < mid1)
        destArray[l++] = gArray[i++];

    // copy remaining values from the second range
    while (j < mid2)
        destArray[l++] = gArray[j++];

    // copy remaining values from the third range
    while (k < high)
        destArray[l++] = gArray[k++];
}

/* Performing the merge sort algorithm on the
given array of values in the rangeof indices
[low, high). low is minimum index, high is
maximum index (exclusive) */
void MergeSort3WayRec(int gArray[], int low,
                      int high, int destArray[])
{
    // If array size is 1 then do nothing
    if (high - low < 2)
        return;

    // Splitting array into 3 parts
    int mid1 = low + ((high - low) / 3);
    int mid2 = low + 2 * ((high - low) / 3) + 1;

    // Sorting 3 arrays recursively
    MergeSort3WayRec(destArray, low, mid1, gArray);
    MergeSort3WayRec(destArray, mid1, mid2, gArray);
    MergeSort3WayRec(destArray, mid2, high, gArray);

    // Merging the sorted arrays
    Merge3(destArray, low, mid1, mid2, high, gArray);
}

void MergeSort3Way(int gArray[], int n)
{
    // if array size is zero return null
    if (n == 0)
        return;

    // creating duplicate of given array
    int fArray[n];

    // copying alements of given array into
    // duplicate array
    for (int i = 0; i < n; i++)
        fArray[i] = gArray[i];

    // sort function
    MergeSort3WayRec(fArray, 0, n, gArray);

    // copy back elements of duplicate array
    // to given array
    for (int i = 0; i < n; i++)
        gArray[i] = fArray[i];
}

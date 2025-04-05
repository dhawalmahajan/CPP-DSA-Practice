// https://www.youtube.com/watch?v=UdO2NeHB46c&list=PLDzeHZWIZsTp4pb_WBRahP1tnipLuX9qM&index=5
// https://www.youtube.com/watch?v=sNaHN4tZmRk

#include <algorithm>
#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(std::vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    { // for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i; j++)
        { // for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Time Complexity = O(n^2)
void insertionSort(std::vector<int> &arr, int n)
{
    // Optimized Solution
    // for (int i = 1; i < n; i++) {
    //    int key = arr[i];
    //    int j = i - 1;
    //    while (j >= 0 && arr[j] > key) {
    //      arr[j + 1] = arr[j];
    //      j--;
    //    }
    //    arr[j + 1] = key;
    //  }

    // Brute force Solution
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

// Optimized Solution

void mergeSort(std::vector<int> &arr, int n)
{
    if (n <= 1)
    {
        return;
    }
    int mid = n / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
}

// Time Complexity: O(nlogn))
//  Brute force
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values
    int mainIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndex++];
    }
    // Merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainIndex++] = first[index1++];
        }
        else
        {
            arr[mainIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort1(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    // sort left part

    mergeSort1(arr, s, mid);

    // sort right part
    mergeSort1(arr, mid + 1, e);

    // merge both parts
    merge(arr, s, e);
}

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    // place pivot at right position
    int pivotIndex = s + count;
    std::swap(arr[pivotIndex], arr[s]);
    // left and right wala part sambhal lete h

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    // partition
    int p = partition(arr, s, e);
    // sort left part
    quickSort(arr, s, p - 1);
    // sort right part
    quickSort(arr, p + 1, e);
}

int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> a = {44, 33, 62, 15};
    selectionSort(a, 4);
    std::cout << "Selection sort: ";
    for (int x : a)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::vector<int> b = {14, 3, 69, 37};
    bubbleSort(b, 4);
    std::cout << "Bubble sort: ";
    for (int x : b)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::vector<int> c = {24, 13, 48, 97, 6, 56};
    insertionSort(c, 6);
    std::cout << "Insertion sort: ";
    for (int x : c)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    int n = 5;
    int arr[5] = {2, 5, 1, 6, 9};
    mergeSort1(arr, 0, n - 1);
    std::cout << "Merge sort: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Quick sort: ";
    int k = 7;
    int arr1[7] = {2, 4, 1, 6, 9, 9, 9};

    quickSort(arr1, 0, k - 1);
    for (int i = 0; i < k; i++)
    {
        std::cout << arr1[i] << " ";
    }
}
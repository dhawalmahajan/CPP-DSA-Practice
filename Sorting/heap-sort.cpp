/* Heap sort in c++ */

#include <iostream>

using namespace std;

// A function to heapify the array.
void MaxHeapify(int a[], int i, int n) {
  int j, temp;
  temp = a[i];
  j = 2 * i;

  while (j <= n) {
    if (j < n && a[j + 1] > a[j]) j = j + 1;
    // Break if parent value is already greater than child value.
    if (temp > a[j]) break;
    // Switching value with the parent node if temp < a[j].
    else if (temp <= a[j]) {
      a[j / 2] = a[j];
      j = 2 * j;
    }
  }
  a[j / 2] = temp;
  return;
}
void HeapSort(int a[], int n) {
  int i, temp;
  for (i = n; i >= 2; i--) {
    // Storing maximum value at the end.
    temp = a[i];
    a[i] = a[1];
    a[1] = temp;
    // Building max heap of remaining element.
    MaxHeapify(a, 1, i - 1);
  }
}
void Build_MaxHeap(int a[], int n) {
  int i;
  for (i = n / 2; i >= 1; i--) MaxHeapify(a, i, n);
}
int main() {
  int n, i;
  cout << "\nEnter the number of data element to be sorted: ";
  cin >> n;
  n++;
  int* arr = new int[n];
  for (i = 1; i < n; i++) {
    cout << "Enter element " << i << ": ";
    cin >> arr[i];
  }
  // Building max heap.
  Build_MaxHeap(arr, n - 1);
  HeapSort(arr, n - 1);

  // Printing the sorted data.
  cout << "\nSorted Data ";

  for (i = 1; i < n; i++) cout << "->" << arr[i];
  cout << "\nTime Complexity: Best case = Avg case = Worst case = O(n logn)";

  return 0;
}

/* Runtime test case:-

Enter the number of data elements to be sorted: 7
Enter element 1: 10
Enter element 2: 8
Enter element 3: 12
Enter element 4: 1
Enter element 5: 2
Enter element 6: 0
Enter element 7: 15

Sorted Data ->0->1->2->8->10->12->15
Time Complexity: Best case = Avg case = Worst case = O(n logn) */

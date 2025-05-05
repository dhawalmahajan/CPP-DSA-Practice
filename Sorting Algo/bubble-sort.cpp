#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int n) {
  for (int i = n - 2; i >= 0; i--) {
    bool swapped = 0;
    for (int j = 0; j <= i; j++) {
      if (arr[j] > arr[j + 1]) {
        swapped = 1;
        swap(arr[j], arr[j + 1]);
      }
    }
    if (swapped == 0) break;
  }
}
int main() {
  int arr[1000];
  int n;
  cout << "enter size of array:";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  bubbleSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
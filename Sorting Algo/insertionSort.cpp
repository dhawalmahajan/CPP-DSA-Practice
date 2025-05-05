#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      } else {
        break;
      }
    }
  }
}
int main() {
  int arr[1000];
  int n;
  cout << "Enter the size of array:";
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  insertionSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
#include <algorithm>
#include <iostream>
#include <vector>

int binarySearch(int arr[], int size, int key) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] == key) {
      return mid;
    }

    if (key > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return -1;
}

int firstOccurence(std::vector<int> &arr, int size, int key) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;
  while (start <= end) {
    if (arr[mid] == key) {
      ans = mid;
      end = mid - 1;
    }

    else if (key > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}

int lastOccurence(std::vector<int> &arr, int size, int key) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;
  while (start <= end) {
    if (arr[mid] == key) {
      ans = mid;
      start = mid + 1;
    }

    else if (key > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}

std::pair<int, int> firstAndLastPosition(std::vector<int> &arr, int n, int k) {
  std::pair<int, int> p;
  p.first = firstOccurence(arr, n, k);
  p.second = lastOccurence(arr, n, k);
  return p;
}

int main() {
  std::cout << "Hello World!\n";
  int even[6] = {2, 4, 6, 8, 12, 18};
  int odd[5] = {3, 8, 11, 14, 16};
  int evenIndex = binarySearch(even, 6, 6);

  std::cout << "Index of 6 is " << evenIndex << std::endl;
  int oddIndex = binarySearch(odd, 5, 14);
  std::cout << "Index of 14 is " << oddIndex << std::endl;

  std::vector<int> arr = {1, 2, 3, 3, 5};
  std::cout << "First occurence of 3 is " << firstOccurence(arr, 5, 3)
            << std::endl;
  std::cout << "Last occurence of 3 is " << lastOccurence(arr, 5, 3)
            << std::endl;

  std::pair<int, int> p = firstAndLastPosition(arr, 5, 3);
  std::cout << p.first << std::endl;
  std::cout << p.second << std::endl;
  return 0;
}
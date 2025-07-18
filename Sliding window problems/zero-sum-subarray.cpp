#include <bits/stdc++.h>
using namespace std;

int findSubarray(vector<int> &arr) {
  int total = 0;
  // map(prefixsum,count)
  unordered_map<int, int> m;
  int prefixsum = 0;
  // initialize by 0,1
  m[0] = 1;
  for (int i = 0; i < arr.size(); i++) {
    prefixsum += arr[i];  // calculate prefix sum
    if (m.count(prefixsum)) {
      total += m[prefixsum];
      m[prefixsum]++;
    } else {
      m[prefixsum] = 1;
    }
  }
  return total;  // Total number of subarrays with sum 0
}
int main() {
  vector<int> arr = {1, 2, -2, 4, -4, 5, -5};
  int total = findSubarray(arr);
  cout << total << endl;
}
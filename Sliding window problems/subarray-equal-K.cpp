#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k) {
  unordered_map<int, int> m;
  m[0] = 1;  // Initialize with 0 sum
  int prefixSum = 0;
  int total = 0;
  for (int i = 0; i < nums.size(); i++) {
    prefixSum += nums[i];
    if (m.count(prefixSum - k)) {
      total += m[prefixSum - k];
      m[prefixSum]++;
    } else {
      m[prefixSum]++;
    }
  }
  return total;
}
int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 5;
  int total = subarraySum(arr, k);
  cout << total << endl;  // Output: 2
  return 0;
}
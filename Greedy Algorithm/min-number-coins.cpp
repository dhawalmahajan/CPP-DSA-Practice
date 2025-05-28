/*
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10,
20, 50, 100, 200, 500, 2000 } and a target value N. Find the minimum number of
coins and/or notes needed to make the change for Rs N. You must return the list
containing the value of coins required.

Input: N = 43
Output: 20 20 2 1
Explaination:
Minimum number of coins and notes needed
to make 43.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


^Constraints:
1 ≤ N ≤ 106
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> minPartition(int N) {
  int currency[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int notes = 0, i = 0;
  vector<int> ans;
  while (N) {
    notes = N / currency[i];
    while (notes--) {
      ans.push_back(currency[i]);
    }
    N %= currency[i];
    i++;
  }
  return ans;
}

int main() {
  int N;
  cout << "Enter the target value: " << endl;
  cin >> N;

  vector<int> result = minPartition(N);
  cout << endl
       << "Minimum number of coins and/or notes needed to make the change for "
          "Rs "
       << N << " are: ";
  for (int coin : result) {
    cout << coin << " ";
  }
  cout << endl;

  return 0;
}
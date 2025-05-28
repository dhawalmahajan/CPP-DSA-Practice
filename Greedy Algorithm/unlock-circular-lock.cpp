/*
Given a lock made up of N different circular rings. Each ring has 0-9 digit
printed on it. There is only one particular code which can open the lock. You
can rotate each ring any number of times in either direction. Given the random
sequence R and the desired sequence D, find the minimum number of rotations
required to open the lock.

Input: R = 222, D = 333
Output: 3
Explaination: Optimal number of rotations for
getting 3 from 2 is 1. There are three 2 to 3
transformations. So answer is 1+1+1 = 3.

Expected Time Complexity: O(logR)
Expected Auxiliary Space: O(1)


*Constraints:
1 ≤ R, D < 1018
*/
#include <bits/stdc++.h>
using namespace std;

int rotationCount(long long R, long long D) {
  int ans = 0;
  int first, second;
  while (R) {
    first = R % 10;
    second = D % 10;
    R /= 10;
    D /= 10;
    ans += min(abs(first - second), 10 - abs(first - second));
  }
  return ans;
}
int main() {
  long long R, D;
  cout << "Enter the random sequence R: ";
  cin >> R;
  cout << "Enter the desired sequence D: ";
  cin >> D;

  int result = rotationCount(R, D);
  cout << "Minimum number of rotations required to open the lock: " << result
       << endl;

  return 0;
}
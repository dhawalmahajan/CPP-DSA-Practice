/*
Given, N Mice and N holes are placed in a straight line. Each hole can
accommodate only 1 mouse. A mouse can stay at his position, move one step right
from x to x + 1, or move one step left from x to x -1. Any of these moves
consumes 1 minute. Write a program to assign mice to holes so that the time when
the last mouse gets inside a hole is minimized. Note: Arrays M and H are the
positions of the N mice and holes.

Input:
N = 3
M = {4, -4, 2}
H = {4, 0, 5}
Output:
4

&Expected Time Complexity: O(N*log(N))
&Expected Auxiliary Space: O(1)

&Constraints:
1 <= N <= 105
-105 <= M[i] , H[i] <= 105

*/
#include <bits/stdc++.h>
using namespace std;

int assignMiceHoles(int N, int M[], int H[]) {
  sort(M, M + N);
  sort(H, H + N);
  int ans = INT_MIN;
  for (int i = 0; i < N; i++) {
    ans = max(ans, abs(M[i] - H[i]));
  }
  return ans;
}
int main() {}
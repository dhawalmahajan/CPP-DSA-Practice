#include <bits/stdc++.h>
using namespace std;

int minimumDays(int S, int N, int M) {
  // code here
  int total = 0, req = S * M;
  int cn = 0;
  for (int i = 1; i <= S; i++) {
    if (i % 7 != 0)
      total += N - M, cn++;
    else
      total -= M;

    req -= M;

    if (total >= req) break;
    if (total < 0) return -1;
  }
  return cn;
}
int main() {
  int S = 5;
  int N = 2;
  int M = 2;
  cout << "Minimum days to buy food: " << minimumDays(S, N, M) << endl;
  return 0;
}

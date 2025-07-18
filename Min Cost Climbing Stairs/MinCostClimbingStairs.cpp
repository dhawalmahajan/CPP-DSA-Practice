#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
// Recursion Way(can cause TLE)
int solve(long long nStairs, int i) {
  if (i == nStairs) return 1;
  if (i > nStairs) return 0;
  return (solve(nStairs, i + 1) + solve(nStairs, i + 2)) % MOD;
}
int countDistinctWays(long long nStairs) { return solve(nStairs, 0); }
// Tabulation And Memoization  Way
int minCostClimbingStairs(vector<int> &cost) {
  int n = cost.size();
  vector<int> dp(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
  }
  return dp[n];
}
int minCostClimbingStairsSpactOptimization(vector<int> &cost) {
  int n = cost.size();
  int prev2 = cost[0];
  int prev1 = cost[1];
  for (int i = 2; i <= n; i++) {
    int curr = cost[i] + min(prev1, prev2);
    prev2 = prev1;
    prev1 = curr;
  }
  return min(prev1, prev2);
}
int main() {
  long long nStairs = 5;
  cout << countDistinctWays(nStairs) << endl;
  vector<int> cost = {10, 15, 20, 5, 12, 17};
  cout << minCostClimbingStairs(cost) << endl;
  cout << minCostClimbingStairsSpactOptimization(cost) << endl;
  return 0;
}
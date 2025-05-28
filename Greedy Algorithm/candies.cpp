
/*
In a candy store, there are n different types of candies available and the
prices of all the N different types of candies are provided to you. You are now
provided with an attractive offer. For every candy you buy from the store and
get K other candies ( all are different types ) for free. Now you have to answer
two questions. Firstly, you have to find what is the minimum amount of money you
have to spend to buy all the n different candies. Secondly, you have to find
what is the maximum amount of money you have to spend to buy all the n different
candies. In both the cases you must utilize the offer i.e. you buy one candy and
get k other candies for free.

Input: n = 4, k = 2, candies[] = {3 2 1 4}
Output: 3 7
Explanation: As according to the offer if you buy one candy you can take at most
two  more for free. So in the first case, you buy the candy which costs 1 and
takes candies worth 3 and 4 for free, also you buy candy worth 2 as well.So min
cost : 1+2 =3. In the second case, you can buy the candy which costs 4 and takes
candies worth 1 and 2 for free, also you need to buy candy worth 3 as well. So
max cost : 3+4 =7.

Constraints:
1 <= n <= 100000
 0 <= k <= N-1
1 <= candies[i] <= 10000

*/
#include <bits/stdc++.h>

using namespace std;
vector<int> candyStore(int candies[], int N, int K) {
  sort(candies, candies + N);
  int minCandies = 0;
  int buy = 0;
  int free = N - 1;
  while (buy <= free) {
    minCandies = minCandies + candies[buy];
    buy++;
    free = free - K;
  }
  int maxCandies = 0;
  buy = N - 1;
  free = 0;
  while (free <= buy) {
    maxCandies = maxCandies + candies[buy];
    buy--;
    free = free + K;
  }
  vector<int> ans;
  ans.push_back(minCandies);
  ans.push_back(maxCandies);
  return ans;
}
int main() {
  int candies[] = {1, 2, 3, 4, 5};
  int N = sizeof(candies) / sizeof(candies[0]);
  int K = 2;
  vector<int> result = candyStore(candies, N, K);
  cout << "Minimum candies: " << result[0] << endl;
  cout << "Maximum candies: " << result[1] << endl;
  return 0;
}
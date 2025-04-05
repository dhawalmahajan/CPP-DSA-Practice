#include <bits/stdc++.h>

using namespace std;
vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);
    int minCandies = 0;
    int buy = 0;
    int free = N - 1;
    while (buy <= free)
    {
        minCandies = minCandies + candies[buy];
        buy++;
        free = free - K;
    }
    int maxCandies = 0;
    buy = N - 1;
    free = 0;
    while (free <= buy)
    {
        maxCandies = maxCandies + candies[buy];
        buy--;
        free = free + K;
    }
    vector<int> ans;
    ans.push_back(minCandies);
    ans.push_back(maxCandies);
    return ans;
}
int main()
{
    int candies[] = {1, 2, 3, 4, 5};
    int N = sizeof(candies) / sizeof(candies[0]);
    int K = 2;
    vector<int> result = candyStore(candies, N, K);
    cout << "Minimum candies: " << result[0] << endl;
    cout << "Maximum candies: " << result[1] << endl;
    return 0;
}
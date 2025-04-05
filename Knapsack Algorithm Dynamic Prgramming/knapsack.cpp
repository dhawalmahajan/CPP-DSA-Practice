#include <bits/stdc++.h>
using namespace std;
// Recursive function to solve the knapsack problem (Brute force approach)
int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    // Base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    // Recursive case
    int include = 0;
    int exclude = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
        exclude = solve(weight, value, index - 1, capacity);
        int ans = max(include, exclude);
        return ans;
    }
}
// Top-Down approch
int solveUsingMemoization(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // Base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }
    // Recursive case
    int include = 0;
    int exclude = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingMemoization(weight, value, index - 1, capacity - weight[index], dp);
    }
    exclude = solveUsingMemoization(weight, value, index - 1, capacity, dp);
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
// Bottom-Up approach
int solveUsingTabulation(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            int exclude = 0;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index - 1][w - weight[index]];
            }
            exclude = dp[index - 1][w];
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // return solve(weight, value, n - 1, maxWeight);
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveUsingMemoization(weight, value, n - 1, maxWeight, dp);
    return solveUsingTabulation(weight, value, n, maxWeight);
}
int main()
{
    vector<int> weight = {1, 2, 3};
    vector<int> value = {10, 15, 40};
    int n = weight.size();
    int maxWeight = 4;
    cout << "Maximum value in knapsack: " << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}
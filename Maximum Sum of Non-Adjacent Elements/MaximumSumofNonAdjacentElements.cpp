#include <bits/stdc++.h>
using namespace std;
int solveUsingTabulation(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    return solveUsingTabulation(nums);
}
int main()
{
    vector<int> nums = {2, 4, 6, 2, 5};
    cout << "Maximum sum of non-adjacent elements: " << maximumNonAdjacentSum(nums) << endl;
    return 0;
}
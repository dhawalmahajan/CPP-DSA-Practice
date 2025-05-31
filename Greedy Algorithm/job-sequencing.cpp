/*
You are given two arrays: deadline[], and profit[], which represent a set of
jobs, where each job is associated with a deadline, and a profit. Each job takes
1 unit of time to complete, and only one job can be scheduled at a time. You
will earn the profit associated with a job only if it is completed by its
deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.


Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Constraints:
1 ≤ deadline.size() == profit.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500

*/
#include <bits/stdc++.h>
using namespace std;
int findParent(int x, vector<int> &parent) {
  if (parent[x] == x) return x;
  return parent[x] = findParent(parent[x], parent);
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
  int n = deadline.size();
  vector<pair<int, int>> jobs(n);
  int maxDeadline = 0;
  for (int i = 0; i < n; i++) {
    jobs[i] = {profit[i], deadline[i]};
    maxDeadline = max(maxDeadline, deadline[i]);
  }

  // Sort jobs by profit descending
  sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

  // Disjoint set for slots
  vector<int> parent(maxDeadline + 1);
  for (int i = 0; i <= maxDeadline; i++) parent[i] = i;

  int maxProfit = 0, jobCount = 0;
  for (auto &job : jobs) {
    int avail = findParent(job.second, parent);
    if (avail > 0) {
      maxProfit += job.first;
      jobCount++;
      parent[avail] = findParent(avail - 1, parent);  // Mark this slot as used
    }
  }
  return {jobCount, maxProfit};
}
int main() {
  vector<int> deadline = {4, 1, 1, 1};
  vector<int> profit = {20, 10, 40, 30};
  vector<int> result = jobSequencing(deadline, profit);
  cout << "Maximum number of jobs: " << result[0] << endl;
  cout << "Total maximum profit: " << result[1] << endl;
  return 0;
}
/*
&Problem Statement:
You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a
2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means
that the i​​​​​​th​​​​ task will be available to process at
enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and
will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains
idle. If the CPU is idle and there are available tasks, the CPU will choose the
one with the shortest processing time. If multiple tasks have the same shortest
processing time, it will choose the task with the smallest index. Once a task is
started, the CPU will process the entire task without stopping. The CPU can
finish a task then start a new one instantly. Return the order in which the CPU
will process the tasks.

^Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]

&Constraints:

tasks.length == n
1 <= n <= 105
1 <= enqueueTimei, processingTimei <= 109
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> getOrder(vector<vector<int>>& tasks) {
  vector<int> ans;
  int n = tasks.size();
  for (int i = 0; i < n; i++) tasks[i].push_back(i);

  sort(tasks.begin(), tasks.end());
  long long timer = tasks[0][0];
  int i = 0;
  // processing time, index
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  // put all tasks in min heap whoes enque time is less than or equal to timer.
  while (!pq.empty() || i < n) {
    while (i < n && timer >= tasks[i][0]) {
      pq.push({tasks[i][1], tasks[i][2]});
      i++;
    }

    // If min heap is empty
    if (pq.empty()) {
      timer = tasks[i][0];
    } else {
      ans.push_back(pq.top().second);
      timer += pq.top().first;
      pq.pop();
    }
  }
  return ans;
}
int main() {
  vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  vector<int> order = getOrder(tasks);
  for (int i : order) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
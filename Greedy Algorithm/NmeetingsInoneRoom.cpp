#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(vector<int> &start, vector<int> &end, int n)
{
    // Your code here

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    int count = 1;
    int ansEnd = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > ansEnd)
        {
            count++;
            ansEnd = v[i].second;
        }
    }
    return count;
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(start, end, start.size());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int> p;                            // Max heap
    priority_queue<int, vector<int>, greater<int>> q; // min heap
    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);
    cout << p.top() << "\n";
    // delete
    p.pop();
    cout << p.top() << "\n";
    cout << p.size() << "\n";
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }

    q.push(10);
    q.push(20);
    q.push(11);
    q.push(18);
    q.push(15);
    cout << q.top() << "\n";
    // delete
    q.pop();
    cout << q.top() << "\n";
    cout << p.size() << "\n";
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}
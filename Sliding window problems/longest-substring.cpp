#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int first = 0, second = 0, length = 0;
    vector<bool> count(256, false);
    while (second < s.size())
    {
        // Repeating character
        while (count[s[second]])
        {
            count[s[first]] = false;
            first++;
        }
        count[s[second]] = true;
        length = max(length, second - first + 1);
        second++;
    }
    return length;
}
int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
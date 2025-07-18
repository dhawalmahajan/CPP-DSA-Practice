#include <bits/stdc++.h>
using namespace std;

int findSubString(string &str) {
  vector<int> count(256, 0);
  int first = 0, second = 0;
  int diff = 0;
  int len = str.size();

  // calculate all unique characters
  while (first < str.size()) {
    if (count[str[first]] == 0) diff++;
    count[str[first]]++;
    first++;
  }
  // clear count array
  for (int i = 0; i < 256; i++) count[i] = 0;
  first = 0;
  while (second < str.size()) {
    // untill diff exist
    while (diff && second < str.size()) {
      if (count[str[second]] == 0) diff--;
      count[str[second]]++;
      second++;
    }
    len = min(len, second - first);
    // when diff is equal to 0 then decrease window size
    while (diff != 1) {
      len = min(len, second - first);
      count[str[first]]--;
      if (count[str[first]] == 0) diff++;
      first++;
    }
  }
  return len;
}
int main() {
  string str = "aabcbcdbca";
  cout << findSubString(str) << endl;
  return 0;
}
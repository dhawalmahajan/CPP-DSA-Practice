
#include <bits/stdc++.h>
using namespace std;

void fun(int **p1) {
  // *p = *p + 10;
  // p1++;
  *p1 = *p1 + 10;
}
void second(int *p1, int *p2) {
  p1 = p2;
  *p1 = 2;
}
int main() {
  // int n = 10;
  // int *p = &n;
  // int **p2 = &p;
  // int ***p3 = &p2;

  // char c[] = "GATE2024";
  // char *p = c;
  // cout << p + p[3] - p[1] << endl;

  // cout << p << endl;
  // cout << &p << endl;
  // cout << *p << endl;
  // cout << p2 << endl;
  // cout << &p2 << endl;
  // cout << **p2 << endl;
  // cout << p3 << endl;
  // cout << &p3 << endl;
  // cout << ***p3 << endl;

  // Modify value of n
  // *p = *p + 5;
  // **p2 = **p2 + 5;
  // ***p3 = ***p3 + 5;
  // cout << p << endl;
  // fun(p2);
  // cout << p << endl;

  int i = 0, j = 1;
  second(&i, &j);
  cout << i << " " << j << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 5, b = 3;
  // Bitwise AND
  cout << "a is " << a << " and b is " << b << endl;
  cout << "a & b: " << (a & b) << endl;  // Output: 1
  // Bitwise OR
  cout << "a | b: " << (a | b) << endl;  // Output: 7
  // Bitwise XOR
  cout << "a ^ b: " << (a ^ b) << endl;  // Output: 6
  // Bitwise NOT
  cout << "~a: " << (~a) << endl;  // Output: -6
  // Left shift
  cout << "a << 1: " << (a << 1) << endl;  // Output: 10
  // Right shift
  cout << "a >> 1: " << (a >> 1) << endl;  // Output: 2

  cout << "a << 2: " << (a << 2) << endl;  // Output: 20
  // Right shift
  cout << "a >> 2: " << (a >> 2) << endl;  // Output: 1

  return 0;
}
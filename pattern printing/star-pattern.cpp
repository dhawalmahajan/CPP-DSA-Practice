#include <bits/stdc++.h>
using namespace std;
void printPattern1(string s = "*") {
  /*
   * * * * *
   * * * * *
   * * * * *
   * * * * *
   * * * * *
   */

  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {
      cout << s << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern2() {
  /*
    1 1 1 1 1
    2 2 2 2 2
    3 3 3 3 3
    4 4 4 4 4
    5 5 5 5 5
   */

  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {
      cout << row << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern3() {
  /*
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
  */
  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {
      cout << col << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printPattern4() {
  /*
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
  */
  for (int row = 1; row <= 5; row++) {
    for (int col = 5; col >= 1; col--) {
      cout << col << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern5() {
  /*
    1 4 9 16 25
    1 4 9 16 25
    1 4 9 16 25
    1 4 9 16 25
    1 4 9 16 25
  */
  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {
      cout << col * col << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern6() {
  /*
    a b c d e
    a b c d e
    a b c d e
    a b c d e
    a b c d e
  */
  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {
      char name = 'a' + (col - 1);
      cout << name << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern7() {
  /*
    a a a a a
    b b b b b
    c c c c c
    d d d d d
    e e e e e
  */
  for (int row = 1; row <= 5; row++) {
    char name = 'a' + (row - 1);
    for (int col = 1; col <= 5; col++) {
      cout << name << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern8() {
  /*
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    16 17 18 19 20
    21 22 23 24 25
  */
  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {
      cout << (row - 1) * 5 + col << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern9() {
  /*
   *
   * *
   * * *
   * * * *
   * * * * *
   */
  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= row; col++) {
      cout << '*' << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern10() {
  /*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
   */
  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= row; col++) {
      cout << col << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern11() {
  /*
    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
   */
  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= row; col++) {
      cout << row << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern12() {
  /*
    1
    2 1
    3 2 1
    4 3 2 1
    5 4 3 2 1
   */
  for (int row = 1; row <= 5; row++) {
    for (int col = row; col >= 1; col--) {
      cout << col << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void printPattern13() {
  /*
    a
    b b
    c c c
    d d d d
    e e e e e
   */
  for (int row = 1; row <= 5; row++) {
    for (int col = row; col >= 1; col--) {
      char name = 'a' + (row - 1);
      cout << name << " ";
    }
    cout << endl;
  }
  cout << endl;
}
int main() {
  printPattern1();
  printPattern2();
  printPattern3();
  printPattern4();
  printPattern5();
  printPattern6();
  printPattern7();
  printPattern8();
  printPattern9();
  printPattern10();
  printPattern11();
  printPattern12();
  printPattern13();
  return 0;
}
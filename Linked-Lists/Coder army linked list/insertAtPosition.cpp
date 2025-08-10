#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* prev;  // Pointer to the previous item
  Node(int value) {
    data = value;
    next = NULL;
    prev = NULL;
  }
};

int main() {
  Node* head = NULL;
  Node* trav = head;
  while (trav != NULL) {
    cout << trav->data << " ";
    trav = trav->next;
  }
}
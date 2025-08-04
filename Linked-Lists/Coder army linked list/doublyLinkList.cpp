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

  // Link list doesn't exist
  if (head == NULL) {
    head = new Node(5);

  }
  // Already exists
  else {
    Node* temp = new Node(5);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }

  Node* trav = head;
  while (trav != NULL) {
    cout << trav->data << " ";
    trav = trav->next;
  }
}
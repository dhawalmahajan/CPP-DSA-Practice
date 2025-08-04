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
  Node *head = NULL, *tail = NULL;
  int arr[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    if (head == NULL) {
      head = new Node(arr[i]);
      tail = head;
    } else {
      Node* temp = new Node(arr[i]);
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
  }
  Node* trav = head;
  while (trav != NULL) {
    cout << trav->data << " ";
    trav = trav->next;
  }
}
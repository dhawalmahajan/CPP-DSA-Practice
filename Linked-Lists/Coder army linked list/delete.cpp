#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int data;
  Node *next;
  Node(int val) {
    data = val;
    next = NULL;
  }
};
// Helper to create a linked list from array (in order)
Node *createList(const vector<int> &arr) {
  Node *head = nullptr;
  Node *tail = nullptr;
  for (int val : arr) {
    Node *temp = new Node(val);
    if (!head) {
      head = tail = temp;
    } else {
      tail->next = temp;
      tail = temp;
    }
  }
  return head;
}
// Helper to print the linked list
void printList(Node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// Delete node at end
void deleteNodeAtEnd(Node *&head) {
  if (!head) return;
  if (!head->next) {
    delete head;
    head = nullptr;
    return;
  }
  Node *curr = head;
  while (curr->next->next) {
    curr = curr->next;
  }
  delete curr->next;
  curr->next = nullptr;
}

// Delete node at start
void deleteNodeAtStart(Node *&head) {
  if (!head) return;
  Node *temp = head;
  head = head->next;
  delete temp;
}

// Delete node at position
void deleteNodeAtPosition(Node *&head, int position) {
  if (!head || position < 0) return;
  if (position == 0) {
    deleteNodeAtStart(head);
    return;
  }
  Node *curr = head;
  for (int i = 0; i < position - 1 && curr->next; i++) {
    curr = curr->next;
  }
  if (curr->next) {
    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
  }
}

// Free the entire list
void freeList(Node *&head) {
  while (head) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};

  // Delete at start
  Node *head1 = createList(arr);
  cout << "\n";
  cout << "Before deleting at start: ";
  printList(head1);
  cout << "\n";
  deleteNodeAtStart(head1);
  cout << "After deleting at start: ";
  printList(head1);
  cout << "\n";
  freeList(head1);

  // Delete at end
  Node *head2 = createList(arr);
  cout << "Before deleting at end: ";
  printList(head2);
  cout << "\n";
  deleteNodeAtEnd(head2);
  cout << "After deleting at end: ";
  printList(head2);
  cout << "\n";

  // Delete at position
  cout << "Before deleting at position 2: ";
  printList(head2);
  cout << "\n";
  deleteNodeAtPosition(head2, 2);
  cout << "After deleting at position 2: ";
  printList(head2);
  freeList(head2);

  return 0;
}
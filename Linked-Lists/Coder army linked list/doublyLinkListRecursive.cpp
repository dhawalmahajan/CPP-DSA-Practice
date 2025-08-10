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
Node* createDoublyLinkList(int arr[], int index, int size, Node* back) {
  if (index == size) return NULL;
  Node* temp = new Node(arr[index]);
  temp->prev = back;
  temp->next = createDoublyLinkList(arr, index + 1, size, temp);
  return temp;
}
int main() {
  Node *head = NULL, *tail = NULL;
  int arr[] = {1, 2, 3, 4, 5};
  head = createDoublyLinkList(arr, 0, 5, NULL);

  Node* trav = head;
  while (trav != NULL) {
    cout << trav->data << " ";
    trav = trav->next;
  }
}
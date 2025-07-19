/*
Given a singly linked list, your task is to remove every kth node from the
linked list.

Input: Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 2
Output: 1 -> 3 -> 5 -> 7

Explanation: After removing every 2nd node of the linked list, the resultant
linked list will be: 1 -> 3 -> 5 -> 7.

Expected Time Complexity:  O(n)
Expected Auxiliary Space:  O(1)

Constraints:
1 <= size of linked list <= 106
1 <= node->data <= 106
1 <= k <= size of linked list

*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* deleteK(Node* head, int k) {
  if (k == 1) return NULL;
  Node *curr = head, *prev = NULL;
  int count = 1;
  while (curr) {
    if (k == count) {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
      count = 1;
    } else {
      prev = curr;
      curr = curr->next;
      count++;
    }
  }
  return head;
}
int main() {
  // Static input
  int k = 2;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
  Node* head = NULL;
  Node* tail = NULL;
  for (int x : arr) {
    Node* newNode = new Node(x);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  head = deleteK(head, k);
  Node* curr = head;
  while (curr) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  return 0;
}
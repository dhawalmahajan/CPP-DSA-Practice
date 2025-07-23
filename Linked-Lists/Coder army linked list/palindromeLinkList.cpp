/*
Given the head of a singly linked list, return true if it is a palindrome or
false otherwise

Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false

The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool isPalindrome(ListNode *head) {
  if (head->next == NULL) return true;
  int count = 0;
  ListNode *temp = head;
  while (temp) {
    count++;
    temp = temp->next;
  }
  count /= 2;
  ListNode *curr = head, *prev = NULL;
  while (count--) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  ListNode *front;
  prev = NULL;
  while (curr) {
    front = curr->next;
    curr->next = prev;
    prev = curr;
    curr = front;
  }
  // prev is pointing to the second list
  // head is pointing to the first list
  ListNode *head1 = head, *head2 = prev;
  // check palindrome
  while (head1) {
    if (head1->val != head2->val) return false;
    head1 = head1->next;
    head2 = head2->next;
  }
  return true;
}

int main() {
  // Static input
  vector<int> arr = {1, 2, 3, 2, 1};
  ListNode *head = NULL, *tail = NULL;
  for (int x : arr) {
    ListNode *newNode = new ListNode(x);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  bool result = isPalindrome(head);
  cout << (result ? "true" : "false") << endl;
  return 0;
}
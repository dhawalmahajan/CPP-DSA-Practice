/*
Given the head of a linked list, remove the nth node from the end of the list
and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  int count = 0;
  ListNode* temp = head;
  while (temp) {
    count++;
    temp = temp->next;
  }
  count -= n;
  ListNode *curr = head, *prev = NULL;
  if (count == 0) {
    temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  while (count--) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = curr->next;
  delete curr;
  return head;
}
int main() {
  // Example usage
  ListNode* head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  int n = 2;
  head = removeNthFromEnd(head, n);

  // Print the modified list
  ListNode* temp = head;
  while (temp) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  // Clean up memory
  while (head) {
    ListNode* toDelete = head;
    head = head->next;
    delete toDelete;
  }

  return 0;
}
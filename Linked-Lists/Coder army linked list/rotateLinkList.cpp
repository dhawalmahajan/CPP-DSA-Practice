/*
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9
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

ListNode* rotateRight(ListNode* head, int k) {
  if (head == NULL || head->next == NULL) return head;
  int count = 0;
  ListNode* temp = head;
  while (temp) {
    count++;
    temp = temp->next;
  }
  k = k % count;
  if (k == 0) return head;
  count -= k;
  ListNode *curr = head, *prev = NULL;
  while (count--) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  ListNode* tail = curr;
  while (tail->next) {
    tail = tail->next;
  }
  tail->next = head;
  return curr;
}
int main() {
  // Static input
  int k = 2;
  vector<int> arr = {1, 2, 3, 4, 5};
  ListNode* head = NULL;
  ListNode* tail = NULL;
  for (int x : arr) {
    ListNode* newNode = new ListNode(x);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  head = rotateRight(head, k);
  ListNode* curr = head;
  while (curr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  return 0;
}
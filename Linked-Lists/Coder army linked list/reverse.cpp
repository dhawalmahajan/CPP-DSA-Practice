/*
Given the head of a singly linked list, reverse the list, and return the
reversed list.

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
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
ListNode* reverseListAlternateApproch(ListNode* head) {
  ListNode *curr = head, *prev = NULL, *future = NULL;
  while (curr) {
    future = curr->next;
    curr->next = prev;
    prev = curr;
    curr = future;
  };
  head = prev;
  return head;
}
ListNode* reverseRecursively(ListNode* curr, ListNode* prev) {
  if (curr == NULL) return prev;
  ListNode* future = curr->next;
  curr->next = prev;
  return reverseRecursively(future, curr);
}
ListNode* reverseListUsingIteration(ListNode* head) {
  vector<int> ans;
  ListNode* temp = head;
  while (temp != NULL) {
    ans.push_back(temp->val);
    temp = temp->next;
  };
  int i = ans.size() - 1;
  temp = head;
  while (temp != NULL) {
    temp->val = ans[i];
    i--;
    temp = temp->next;
  }
  return head;
}
ListNode* reverseList(ListNode* head) {
  //* Approch 1 Call
  return reverseRecursively(head, NULL);
  //* Approch 2 Call
  // return reverseListAlternateApproch(head);
  //* Approch 3 Call
  // return reverseListUsingIteration(head);
}
int main() {
  // Example usage
  ListNode* head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  head = reverseList(head);
  // Print reversed list
  ListNode* temp = head;
  while (temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  // Clean up memory
  temp = head;
  while (temp != NULL) {
    ListNode* toDelete = temp;
    temp = temp->next;
    delete toDelete;
  }

  return 0;
}
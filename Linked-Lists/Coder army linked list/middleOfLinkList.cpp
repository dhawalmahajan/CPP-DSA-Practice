/*
Given the head of a singly linked list, return the middle node of the linked
list.

If there are two middle nodes, return the second middle node.
* Input: head = [1,2,3,4,5]
* Output: [3,4,5]
^ Explanation: The middle node of the list is node 3.

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
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

ListNode* conventionalApproch(ListNode* head) {
  int count = 0;
  ListNode* temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  };
  count /= 2;
  temp = head;
  while (count--) temp = temp->next;
  return temp;
}
ListNode* slowAndFastPointerApproch(ListNode* head) {
  ListNode *slow = head, *fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
ListNode* middleNode(ListNode* head) { return slowAndFastPointerApproch(head); }
int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode* middle = middleNode(head);
  cout << "Middle Node Value: " << middle->val << endl;  // Output: 3

  return 0;
}
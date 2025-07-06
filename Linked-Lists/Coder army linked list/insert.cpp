
#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int val) {
    data = val;
    next = NULL;
  }
};

void insertAtStart() {
  Node* head = nullptr;
  int arr[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    Node* temp = new Node(i);
    temp->next = head;
    head = temp;
  }
  cout << "Elements of linked list are: ";
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
    // delete temp;  // Free the memory of the node
  }
  cout << endl;
}
void insertAtEnd() {
  int arr[] = {1, 2, 3, 4, 5};
  Node *head, *tail;
  head = tail = nullptr;

  for (int i = 0; i < 5; i++) {
    if (head == NULL) {
      head = new Node(arr[i]);
      tail = head;
    } else {
      tail->next = new Node(arr[i]);
      tail = tail->next;
    }
  }
  cout << "Elements of linked list are: ";
  Node* temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void insertNodeAtPosition() {
  int arr[] = {1, 2, 3, 4, 5};
  int x = 2;
  int value = 30;
  Node* head = NULL;
  Node* tail = NULL;
  for (int i = 0; i < 5; i++) {
    Node* newNode = new Node(arr[i]);
    if (!head) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Step 2: Traverse to the (x-1)th node
  Node* temp = head;
  for (int i = 1; i < x && temp != NULL; i++) {
    temp = temp->next;
  }

  // Step 3: Insert the new node after position x-1
  if (temp != NULL) {
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // Print the list
  cout << "Elements of linked list after insertion are: ";
  Node* temp2 = head;
  while (temp2) {
    cout << temp2->data << " ";
    temp2 = temp2->next;
  }
  cout << endl;
}
Node* createLinkList(int arr[], int index, int size) {
  if (index == size) return NULL;
  Node* temp = new Node(arr[index]);
  temp->next = createLinkList(arr, index + 1, size);
  return temp;
}
void linkListRecursive() {
  int arr[] = {2, 4, 6, 8, 10};
  Node* head = createLinkList(arr, 0, 5);
  cout << "Elements of linked list are: ";
  Node* temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
Node* insertAtStartRecursive(int arr[], int index, int size, Node*& prev) {
  if (index == size) return prev;
  Node* temp = new Node(arr[index]);
  temp->next = prev;
  prev = temp;
  return insertAtStartRecursive(arr, index + 1, size, prev);
}
void insertRecursiveExample() {
  int arr[] = {1, 2, 3, 4, 5};
  Node* head = NULL;
  insertAtStartRecursive(arr, 0, 5, head);
  cout << "Elements of linked list are: ";
  Node* temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
    // delete temp;  // Free the memory of the node
  }
  cout << endl;
}
int main() {
  cout << "Insert at start:" << endl;
  insertAtStart();
  cout << "\n";
  cout << "Insert at end:" << endl;
  insertAtEnd();
  cout << "\n";
  cout << "Insert using recursion:" << endl;
  linkListRecursive();
  cout << "\n";
  cout << "Insert at start using recursion:" << endl;
  insertRecursiveExample();
  cout << "\n";
  cout << "Insert at position:" << endl;
  insertNodeAtPosition();
  cout << "\n";
  return 0;
}

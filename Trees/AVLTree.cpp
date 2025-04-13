#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;

    Node(int val)
    {
        height = 1;
        data = val;
        left = right = NULL;
    }
};
int getHeight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}

int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}
// L L imbalance
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;
    child->right = root;
    root->left = childRight;
    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
// R R Imbalance
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;
    child->left = root;
    root->right = childLeft;
    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *insert(Node *root, int key)
{
    // Doesn't exist
    if (!root)
        return new Node(key);
    // Exist
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        // duplicate elements not allowed in this program.
        return root;
    }
    // Update height of this ancestor node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // Get the balance factor
    int balance = getBalance(root);
    // Left Left Unbalancing Case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }
    // right right Unbalancing case
    else if (balance < -1 && root->right->data < key)
    {
        return leftRotation(root);
    }
    // Left Right Unbalancing Case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right Left Unbalancing Case
    else if (balance < -1 && root->right->data > key)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No Unbalancing
    else
    {
        return root;
    }
}

void preOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);
    cout << "\n"
         << "Inorder traversal of the constructed AVL tree is \n";
    inOrder(root);
    return 0;
}
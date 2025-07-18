#include <bits/stdc++.h>
using namespace std;

class TrieNode {
 public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char data) {
    this->data = data;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};
class Trie {
 public:
  TrieNode *root;
  Trie() { root = new TrieNode('\0'); }

  void insertUtil(TrieNode *root, string word) {
    if (word.length() == 0) {
      root->isTerminal = true;
      return;
    }
    int index = word[0] - 'A';
    TrieNode *child;
    // if the child is not present, create a new node
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }
    insertUtil(child, word.substr(1));
  }
  void insertWord(string word) { insertUtil(root, word); }
  bool searchUtil(TrieNode *root, string word) {
    if (word.length() == 0) {
      return root->isTerminal;
    }
    int index = word[0] - 'A';
    TrieNode *child;
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      return false;
    }
    return searchUtil(child, word.substr(1));
  }
  bool search(string word) { return searchUtil(root, word); }
  bool startsWith(string prefix) { return prefixSearchUtil(root, prefix); }
  // Search prefix of string
  bool prefixSearchUtil(TrieNode *root, string word) {
    if (word.length() == 0) {
      return true;
    }
    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      return false;
    }
    return prefixSearchUtil(child, word.substr(1));
  }
  // remove the word
  void removeUtil(TrieNode *root, string word) {
    if (word.length() == 0) {
      root->isTerminal = false;
      return;
    }
    int index = word[0] - 'A';
    TrieNode *child;
    if (root->children[index] != NULL) {
      child = root->children[index];
      removeUtil(child, word.substr(1));
    } else {
      return;
    }
    // if the child is not terminal and has no children, delete it
    if (child->isTerminal == false) {
      for (int i = 0; i < 26; i++) {
        if (child->children[i] != NULL) {
          return;
        }
      }
      delete child;
      root->children[index] = NULL;
    }
  }
  void remove(string word) { removeUtil(root, word); }
};

int main() {
  Trie *t = new Trie();
  t->insertWord("HELLO");
  cout << "present or not: " << t->search("HELLO") << endl;
  t->remove("HELLO");
  cout << t->root->data << endl;
  return 0;
}
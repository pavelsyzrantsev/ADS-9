// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class PMTree {
 private:
  struct Node {
    char data;
    std::vector<Node*> children;
  };
  Node* _root;
  Node* createTree(Node* root, std::vector<char>& numbers) {
    if (root == nullptr) {
      root = new Node;
      _root = root;
      root->data = '\0';
      for (int i = 0; i < numbers.size(); ++i) {
        Node* node = new Node;
        node->data = numbers[i];
        std::vector<char> newnumbers;
        for (int j = 0; j < numbers.size(); ++j) {
          if (i != j) newnumbers.push_back(numbers[j]);
        }
        createTree(node, newnumbers);
        root->children.push_back(node);
      }
    } else {
      for (int i = 0; i < numbers.size(); ++i) {
        Node* node = new Node;
        node->data = numbers[i];
        std::vector<char> newnumbers;
        for (int j = 0; j < numbers.size(); ++j) {
          if (i != j) newnumbers.push_back(numbers[j]);
        }
        createTree(node, newnumbers);
        root->children.push_back(node);
      }
    }
    return root;
  }
  void getPerms(Node* root, std::vector<std::vector<char>>& v,
std::vector<char> perm) {
    if (root->children.empty()) {
      v.push_back(perm);
    } else {
      for (int i = 0; i < root->children.size(); ++i) {
        perm.push_back(root->children[i]->data);
        getPerms(root->children[i], v, perm);
        perm.erase(perm.end()-1);
      }
    }
  }
  int fact(int num) {
    int f = 1;
    for (int i = 1; i <= num; i++) {
      f *= i;
    }
    return f;
  }
  void getPerm(Node* root, std::vector<char>& perm, int num) {
    if (root->children.size() > 0) {
      int del = fact(root->children.size()-1);
      perm.push_back(root->children[num / del]->data);
      getPerm(root->children[num / del], perm, num % del);
    }
  }

 public:
  explicit PMTree(std::vector<char> numbers) : _root(nullptr) {
    createTree(_root, numbers);
  }
  ~PMTree() {}
  void get(std::vector<std::vector<char>>& v) {
    std::vector<char> perm;
    getPerms(_root, v, perm);
  }
  std::vector<char> getPermByNumber(int num) {
    std::vector<char> perm;
    if (num + 1 <= fact(_root->children.size()))
      getPerm(_root, perm, num);
    return perm;
  }
};
std::vector<std::vector<char>> getAllPerms(PMTree tree);
std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);
#endif  // INCLUDE_TREE_H_

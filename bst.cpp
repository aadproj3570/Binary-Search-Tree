#include <iostream>
#include <string>
#include "bst.h"
#include <cmath>
using namespace std;

bst::bst() {

  data = 0;
  left = right = NULL;
  
}

bst::bst(int val) {

  data = val;
  left = right = NULL;
  
}

bst* bst::insert(bst *cur, int a) {

  bst *temp = new bst();
  temp->data = a;
  
  if(cur == nullptr) {
    return new bst(a);
  }
  if(cur->data > temp->data) {
    cur->left = insert(cur->left, a);
  }
  if(cur->data < temp->data) {
    cur->right = insert(cur->right, a);
  }
  return cur;
  
}
int bst::numNodes(bst *cu, int level) {

  int total = 0;
  for(int i = 0; i < level; i++) {
    total += pow(2, i);
  }
  return total;
  
}
bool bst::search(int key, bst *cur) {

  if(cur == NULL)
    return false;
  if(key < cur->data) {
    return search(key, cur->left);
  } else if(key > cur->data) {
    return search(key, cur->right);
  } else {
    return true;
  }
  
}
void bst::inorder(bst *cur) {

    if(cur != nullptr) {
      inorder(cur->left);
      cout << cur->data << endl;
      inorder(cur->right);
    }
}
void bst::preorder(bst *cur, ostream &out, string s) {

    if(cur != nullptr) {
      cout << "[x" << s << "] " << cur->data << endl;
      out << "[x" << s << "] " << cur->data << endl;
      s += "l";
      preorder(cur->left, out, s);
      s.pop_back();
      s += "r";
      preorder(cur->right, out, s);
    }
  
}
void bst::postorder(bst *cur) {

    if(cur != nullptr) {
      postorder(cur->left);
      postorder(cur->right);
      cout << cur->data << endl;
    }
  
}
void bst::print(bst *root, ostream &out) {

  bst *cur = root;
  if(root == nullptr) {
    return;
  }
  print(cur->left, out);
  print(cur->right, out);
  cout << root->data << endl;
  out << root->data << endl;
  
}
bool bst::isBST(bst *root) {

  if(root == nullptr) {
    return true;
  }
  bool leftBT = false;
  bool rightBT = false;
  bst *left = root->left;
  bst *right = root->right;

  if(left == nullptr) {
    leftBT = false;
  } else if(left->data < root->data) {
    leftBT = isBST(left);
  }
  if(right == nullptr) {
    rightBT = false;
  } else if(left->data > root->data) {
    rightBT = isBST(right);
  }
  return leftBT && rightBT;
  
}
bst* bst::lg(bst *root) {

  if(root == nullptr || root->right == nullptr ) {
    return root;
  }
  return lg(root->right);
  
}

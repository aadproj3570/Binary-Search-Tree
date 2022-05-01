#include <iostream>
using namespace std;

class bst {
private:
      int data;
      bst *left;
      bst *right;
public:
      bst();
      bst(int);
      bst* insert(bst *cur, int);
      int numNodes(bst *cur, int);
      void deleteNode();
      bool search(int, bst *cur);
      void print(bst *cur, ostream &out);
      bool isBST(bst *root);
      void inorder(bst *cur);
      void preorder(bst *cur, ostream &out, string);
      void postorder(bst *cur);
      bst* lg(bst *root);
};
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ArgumentManager.h"
#include "bst.h"
using namespace std;

int main(int argc, char* argv[]) {
  
    ArgumentManager am(argc, argv);
    string ifile = am.get("input"); //get the filename of argument name "input"
    string ofile = am.get("output"); //get the filename of argument name "output"
    ifstream input(ifile);
    ofstream output(ofile);

    int vals;
    bst tree;
    bst *root = NULL;
    input >> vals;
    root = tree.insert(root, vals);
  
    while(input >> vals) {
      tree.insert(root, vals);
      cout << vals << endl;
    }
    //tree.print(root, output);
    tree.preorder(root, output, "");
  
    return 0;

}
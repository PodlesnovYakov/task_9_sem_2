#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
struct tree
{
    char id;
    tree *left;
    tree *right;

};
void show(tree *root, int n)
{
    if (root != NULL)
    {
        show(root->left, n + 1);
        cout << setw(n*3)<< root->id<< endl;
        show(root->right, n + 1);
    }
}

#endif // TREE_H_INCLUDED

// Given the root of a binary tree, return the same tree where every subtree(of the given tree) not containing a 1 has been removed.

//     A subtree of a node node is node plus every node that is a descendant of node.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        traverseTree(root);
        return root;
    }

    bool traverseTree(TreeNode *&root)
    {
        if (root == nullptr)
            return false;

        bool checkLeft = traverseTree(root->left);
        bool checkRight = traverseTree(root->right);
        if ((root->val == 0) && !checkLeft && !checkRight)
        {
            root = nullptr;
            return false;
        };
        return true;
    }
};

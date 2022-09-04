// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef pair<pair<int,int>, int> pii;
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        traverseTree(root, 0, 0, q);
        pii tmpVector;
        tmpVector = q.top();         
        int tmp = tmpVector.first.first;
        vector<int> tmpAns;
        while (!q.empty()){
            tmpVector = q.top(); q.pop();
            if (tmpAns.empty() || tmp == tmpVector.first.first ){
                tmpAns.push_back(tmpVector.second);
            } else {
                ans.push_back(tmpAns);
                tmpAns = {tmpVector.second};
                tmp = tmpVector.first.first;
            }
        }
        ans.push_back(tmpAns);
        return ans;
    }
    
    void traverseTree(TreeNode* root, int row, int col,  priority_queue<pii, vector<pii>, greater<pii>> &q){
        if (root == nullptr)
            return;
        q.push(make_pair(make_pair(col, row), root->val));
        traverseTree(root->left, row+1, col-1, q);
        traverseTree(root->right, row+1, col+1, q);
    }
};
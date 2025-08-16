#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
            return isIdentical(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* treeOne, TreeNode* treeTwo) {
        if (!treeOne && !treeTwo) 
            return true;
    
        if (!treeOne || !treeTwo) 
            return false;
      
        return treeOne->val == treeTwo->val &&
               isIdentical(treeOne->left, treeTwo->left) &&
               isIdentical(treeOne->right, treeTwo->right);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(26);
    root1->right = new TreeNode(3);
    root1->right->right = new TreeNode(3);
    root1->left = new TreeNode(10);
    root1->left->left = new TreeNode(4);
    root1->left->left->right = new TreeNode(30);
    root1->left->right = new TreeNode(6);

    TreeNode* root2 = new TreeNode(10);
    root2->right = new TreeNode(6);
    root2->left = new TreeNode(4);
    root2->left->right = new TreeNode(30);

    Solution sol;
    if (sol.isSubtree(root1, root2))
        cout << "True";
    else
        cout << "False";

    return 0;
}
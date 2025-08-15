#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; 

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; 

        if (abs(leftHeight - rightHeight) > 1) return -1; 

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    Solution s;
    cout << (s.isBalanced(root) ? "Balanced" : "Not Balanced") << endl;
}
#include <iostream>
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
    bool check(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL)
            return true;
        
        if(l == NULL || r == NULL)
            return false;
        
        if((l -> val == r -> val) && check(l -> left, r -> right) && check(l -> right, r -> left))
            return true;

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;

        return check(root -> left, root -> right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    cout << (solution.isSymmetric(root) ? "True" : "False") << endl;
    
    return 0;
}
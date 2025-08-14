#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Preorder Traversal using recursion
void printPreorder(TreeNode* node) {
    if(node == NULL)
        return;
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    return;
}

// Preorder Traversal without recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

    while (root != nullptr) {  
        if (root->left == nullptr) {  
            res.push_back(root->val);
            root = root->right;
        } else {
            TreeNode* curr = root->left;
            while (curr->right != nullptr && curr->right != root) {  
                curr = curr->right;
            }

            if (curr->right == root) {
                curr->right = nullptr;  
                root = root->right;
            } else {
                res.push_back(root->val);
                curr->right = root;
                root = root->left;
            }
        }
    }

    return res;
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

    cout << "Preorder Traversal using recursion: ";
    printPreorder(root);
    cout << endl;
    cout << "Preorder Traversal without recursion: ";
    Solution sol;
    vector<int> preorderResult = sol.preorderTraversal(root);
    for (int data : preorderResult) {
        cout << data << " ";
    }
    return 0;
};
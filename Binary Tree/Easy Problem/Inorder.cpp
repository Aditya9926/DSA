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

// Inorder Traversal using recursion
void printInorder(TreeNode* node)
{
    if (node == nullptr)
        return;

    // First recur on left subtree
    printInorder(node->left);

    // Now deal with the node
    cout << node->val << " ";

    // Then recur on right subtree
    printInorder(node->right);
}

// Inorder Traversal without recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top(), s.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }
};

// Morris Inorder Traversal
vector<int> inOrder(TreeNode* root) {
    vector<int> res;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          
            // If no left child, visit this node 
            // and go right
            res.push_back(curr->val);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            TreeNode* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return res;
}

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

    cout << "Inorder Traversal using recursion: ";
    printInorder(root);
    cout << endl;

    cout << "Inorder Traversal without recursion: ";
    Solution sol;
    vector<int> inorderResult = sol.inorderTraversal(root);
    for (int data : inorderResult) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Morris Inorder Traversal: ";
    printInorder(root);
    return 0;
}
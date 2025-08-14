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

// Postorder travelsal with recursion
void printPostorder(TreeNode* node) {
    if(node == NULL)
        return;
    
    printPostorder(node->left);
    
    printPostorder(node->right);
    
    cout << node->val << " ";
}

// Postorder travelsal without recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
    stack<TreeNode*> st;
    while (true) {
        while (root) {
            st.push(root);
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            return res;
        root = st.top();
        st.pop();
        if (!st.empty() && st.top() == root)
            root = root->right;
        else {
            res.push_back(root->val);
            root = nullptr;
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

    cout << "Postorder Traversal using recursion: ";
    printPostorder(root);
    cout << endl;
    cout << "Postorder Traversal without recursion: ";
    Solution sol;
    vector<int> result = sol.postorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
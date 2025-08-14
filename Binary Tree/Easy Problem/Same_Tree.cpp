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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            return (p == q); 
        }
        return (p->val == q->val) && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};

int main() {

    TreeNode* r1 = new TreeNode(1);    
    r1->left = new TreeNode(2);   
    r1->right = new TreeNode(3); 
    r1->left->left = new TreeNode(4); 

    TreeNode* r2 = new TreeNode(1);    
    r2->left = new TreeNode(2);   
    r2->right = new TreeNode(3);  
    r2->left->left = new TreeNode(4);

    Solution sol;
    if (sol.isSameTree(r1, r2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
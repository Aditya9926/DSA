#include <iostream>
#include <functional>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        
        if(!head -> next)
            return new TreeNode(head -> val);
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = NULL;

        while(fast && fast -> next){
            slow_prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        TreeNode* root = new TreeNode(slow -> val);
        slow_prev -> next = NULL;
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(slow -> next);

        return root;
    }
};

int main() {
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    cout<<"Given Linked List: "<<endl;
    ListNode* temp = head;
    while(temp) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    
    cout<<endl;
    TreeNode* root = Solution().sortedListToBST(head);
    cout<<"Peorder Traversal of constructed BST: "<<endl;
    function<void(TreeNode*)> preOrder = [&](TreeNode* node) {
        if(!node) return;
        cout<<node->val<<" ";
        preOrder(node->left);
        preOrder(node->right);
    };
    preOrder(root);
    cout<<endl;
    return 0;
}
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    // Brute Force Approach
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        // Count the number of nodes in the linked list
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int mid = count / 2;
        temp = head;

        // Traverse to the middle node
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        return temp;
    }
    
    // Optimal Approach (Using Two Pointers)
    ListNode* middleNodeOptimal(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast pointer two steps and slow pointer one step
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // When fast pointer reaches the end, slow pointer will be at the middle
        return slow;
    }
};

int main(){
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    node1->next->next->next = new ListNode(4);
    node1->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* middleBrute = sol.middleNode(node1);
    cout << "Middle Node Value (Brute Force) : " << middleBrute->val << endl;
    ListNode* middle = sol.middleNodeOptimal(node1);
    cout << "Middle Node Value (Two Pointers) : " << middle->val << endl;

    return 0;
}

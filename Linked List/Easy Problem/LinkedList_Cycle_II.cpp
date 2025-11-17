#include<iostream>
using namespace std;

class ListNode{
    public :
        int val;
        ListNode* next;
        ListNode(int x){
            val = x;
            next = NULL;
        }
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;
            bool iscycle = false;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    iscycle = true;
                    break;
                }
            }
            if(!iscycle){
                return NULL;
            }
            slow = head;
            ListNode* prev = NULL;
            while(slow != fast){
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL; // Cycle removed.
            return slow;
        }
};

int main(){
    ListNode* Node = new ListNode(3);
    Node->next = new ListNode(2);
    Node->next->next = new ListNode(0);
    Node->next->next->next = new ListNode(-4);
    Node->next->next->next->next = Node->next;

    ListNode* head = Node;
    Solution solution;
    ListNode* cycleStartNode = solution.detectCycle(head);
    if(cycleStartNode){
        cout << "Cycle detected at node with value: " << cycleStartNode->val << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }
}
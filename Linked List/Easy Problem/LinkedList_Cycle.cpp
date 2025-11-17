#include<iostream>
using namespace std;

class ListNode{
    public :
        int val;
        ListNode* Node;
        ListNode* next;
        ListNode(int x){
            val = x;
            next = NULL;
        }

        bool hasCycle(ListNode *head){
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    return true;
                }
            }
            return false;
        }
};

int main(){
    ListNode* Node = new ListNode(3);
    Node->next = new ListNode(2);
    Node->next->next = new ListNode(0);
    Node->next->next->next = new ListNode(-4);
    Node->next->next->next->next = Node->next; // Creating a cycle for testing

    ListNode* head = Node;
    bool result = Node->hasCycle(head);
    if(result){
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }
}
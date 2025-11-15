#include<iostream>
using namespace std;

class ListNode{
    public :
    int val;
    ListNode* next;

    ListNode(int v){
        val = v;
        next = NULL;
    }

    static ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main(){
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    node1->next->next->next = new ListNode(4);
    node1->next->next->next->next = new ListNode(5);

    ListNode* reversedHead = ListNode::reverseList(node1);
    ListNode* temp = reversedHead;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
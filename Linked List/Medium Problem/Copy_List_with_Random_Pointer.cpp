#include<iostream>
#include<unordered_map>
using namespace std;

class ListdNode{
    public :
        int data;
        ListdNode* next;
        ListdNode* random;
        ListdNode(int val){
            data = val;
            next = NULL;
            random = NULL;
        }
};

class Solution{
    public : 
        ListdNode* copyRandomList(ListdNode* head){
            if(head == NULL){
                return NULL;
            }

            unordered_map<ListdNode*,ListdNode*> m;
            ListdNode* newhead = new ListdNode(head->data);
            ListdNode* oldtemp = head->next;
            ListdNode* newtemp = newhead;
            m[head] = newhead;

            while(oldtemp != NULL){
                ListdNode* copynode = new ListdNode(oldtemp->data);
                m[oldtemp] = copynode;
                newtemp->next = copynode;
                oldtemp = oldtemp->next;
                newtemp = newtemp->next;
            }

            oldtemp = head; newtemp = newhead;
            while(oldtemp != NULL){
                newtemp->random = m[oldtemp->random];
                oldtemp = oldtemp->next;
                newtemp = newtemp->next;
            }
            return newhead;
        }
};

int main(){
    // Creating a linked list with random pointers for testing
    ListdNode* Node1 = new ListdNode(7);
    ListdNode* Node2 = new ListdNode(13);
    ListdNode* Node3 = new ListdNode(11);
    ListdNode* Node4 = new ListdNode(10);
    ListdNode* Node5 = new ListdNode(1);

    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next = Node5;

    Node2->random = Node1;
    Node3->random = Node5;
    Node4->random = Node3;
    Node5->random = Node1;

    Solution solution;
    ListdNode* copiedListHead = solution.copyRandomList(Node1);

    // Print the copied list to verify
    ListdNode* curr = copiedListHead;
    while(curr != NULL){
        cout << "Node Value: " << curr->data << ", ";
        if(curr->random != NULL){
            cout << "Random points to: " << curr->random->data << endl;
        } else {
            cout << "Random points to: NULL" << endl;
        }
        curr = curr->next;
    }
}
#include<iostream>
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

            // Step 1: Create new nodes and insert them next to original nodes
            ListdNode* curr = head;
            while(curr != NULL){
                ListdNode* newNode = new ListdNode(curr->data);
                newNode->next = curr->next;
                curr->next = newNode;
                curr = newNode->next;
            }

            // Step 2: Assign random pointers to the new nodes
            curr = head;
            while(curr != NULL){
                if(curr->random != NULL){
                    curr->next->random = curr->random->next;
                }
                curr = curr->next->next;
            }

            // Step 3: Separate the two lists
            curr = head;
            ListdNode* newHead = head->next;
            ListdNode* copyCurr = newHead;

            while(curr != NULL){
                curr->next = curr->next->next;
                if(copyCurr->next != NULL){
                    copyCurr->next = copyCurr->next->next;
                }
                curr = curr->next;
                copyCurr = copyCurr->next;
            }

            return newHead;
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
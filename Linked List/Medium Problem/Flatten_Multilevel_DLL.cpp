#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* prev;
    Node* next;
    Node* child;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution{
    public :
    Node* flatten(Node* head){
        if(head == NULL){
            return head;
        } 
        
        Node* curr = head;

        while(curr != NULL){
            if(curr->child != NULL){
                //  Flatten the child list first
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // Find the tail of the flattened child list
                while(curr->next != NULL){
                    curr = curr->next;
                }

                // Attach the next part
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->child->next = new Node(12);
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->next = new Node(10);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Solution sol;
    Node* flatHead = sol.flatten(head);
    Node* curr = flatHead;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}
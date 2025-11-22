#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
    public :
    Node* reverseList(Node* head, int k){
        if(head == NULL || k <= 1){
            return head;
        }

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        // Reverse first k nodes of the linked list
        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Now next points to (k+1)th node
        // Recursively call for the list starting from current.
        if(next != NULL){
            head->next = reverseList(next, k);
        }

        // prev is now head of the reversed list
        return prev;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;

    Solution sol;
    Node* newHead = sol.reverseList(head, k);

    // Print reversed list
    Node* curr = newHead;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
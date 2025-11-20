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

class CircularList{
    public :
    Node* head;
    Node* tail;

    CircularList(){
        head = tail = NULL;
    }

    void insertbeg(int val){
        Node* newnode = new Node(val);
        if(tail == NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
    }

    // Function to print the Circular Linked List.
    void printLL(){
        if(head == NULL){
            return;
        }
        cout << head->data << " -> ";
        Node* temp = head->next;
        while(temp != head){
            cout << temp->data << " -> ";
            temp = temp-> next;
        }
        cout << temp->data << endl;
    }
}; 

int main(){
    CircularList cll;
    cll.insertbeg(1);
    cll.insertbeg(2);
    cll.insertbeg(3);
    cll.printLL();
}
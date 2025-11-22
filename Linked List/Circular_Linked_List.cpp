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

    // Function to insert a node at the beginning of the Circular Linked List.
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

    // Function to insert a node at the end of the Circular Linked List.
    void insertend(int val){
        Node* newnode = new Node(val);
        if(tail == NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    // Delete a node from the beginning of the Circular Linked List.
    void deletebeg(){
        if(head == NULL){
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    // Delete a node from the end of the Circular Linked List.
    void deleteend(){
        if(head == NULL){
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
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
    cll.insertend(4);
    cll.insertend(5);
    cout << "Circular Linked List before deleting element : ";
    cll.printLL();
    
    cll.deletebeg();
    cll.deleteend();
    cout << "Circular Linked List after deleting element : ";
    cll.printLL();
}
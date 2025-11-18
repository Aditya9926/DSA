#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList
{
public:
    Node *head;
    Node *tail;

    DoublyList()
    {
        head = tail = NULL;
    }

    // Function to Push elements at front of Doubly Linked List.
    void pushfront(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    // Function to Push elements at back of Doubly Linked List.
    void pushback(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
    }

    // Pop Front Function to pop element at the front.
    void popfront(){
        Node* temp = head;

        if(head == NULL){
            cout << "Empty Linked List." << endl;
            return;
        }

        head = head-> next;
        if(head != NULL){
            head->prev = NULL;
        }

        temp-> next = NULL;
        delete temp;
    }

    // Pop Back Function to pop element at the back.
    void popback(){
        if(head == NULL){
            cout << "Empty Linked List." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail != NULL){
            tail-> next = NULL;
        }
        temp-> prev = NULL;
        delete temp;
    }

    // Function to print the Doubly Linked List.
    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

};

int main()
{
    DoublyList dl;
    dl.pushback(5);
    dl.pushback(6);
    dl.pushfront(4);
    dl.pushfront(3);
    dl.pushfront(2);
    dl.pushfront(1);

    cout << "Doubly Linked List Before Pop : ";
    dl.printLL();

    cout << endl;
    dl.popfront();
    dl.popback();
    cout << "Doubly Linked List after Pop : ";
    dl.printLL();
}
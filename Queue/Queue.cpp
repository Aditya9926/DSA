#include<iostream>
#include<vector>

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

class Queue{
    Node* head;
    Node* tail;
    public :
    Queue(){
        head = tail = NULL;
    }

    void push(int val){
        Node* newnode = new Node(val);
        if(empty()){
            head = tail = newnode;
        }
        else{
            tail-> next = newnode;
            tail = newnode;
        }
    }
    
    void pop(){
        if(empty()){
            cout << "Queue is Empty.";
            return;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int front(){
        if(empty()){
            cout << "Queue is Empty.";
            return -1;
        }
        else{
            return head->data; 
        }
    }

    bool empty(){
        return head == NULL;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << endl; // Output: 10
    q.pop();
    cout << q.front() << endl; // Output: 20
    q.pop();
    cout << q.front() << endl; // Output: 30
    q.pop();
    cout << q.empty() << endl; // Output: 1 (true)
    return 0;
}
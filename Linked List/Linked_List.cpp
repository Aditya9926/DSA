#include<iostream> 
using namespace std;

// Node Class to create new nodes.
class Node{
    public :
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* Head;
    Node* Tail;

    public :
    // Constructor to initialize Head and Tail.
    List(){
        Head = Tail = NULL;
    }

    // Function to Push elements at front of Linked List.
    void pushfront(int val){
        Node* newnode = new Node(val);
        if(Head == NULL){
            Head = Tail = newnode;
            return;
        }
        else{
            newnode-> next = Head;
            Head = newnode;
        }
    }

    // Function to Push elements at back of Linked List.
    void pushback(int val){
        Node* newnode = new Node(val);
        if(Head == NULL){
            Head = Tail = newnode;
            return;
        }
        else{
            Tail-> next = newnode;
            Tail = newnode;
        }
    }

    // Pop Front Function to pop element at the front.
    void popfront(){
        Node* temp = Head;
        if(Head == NULL){
            cout << "Empty Linked List." << endl;
            return;
        }
        Head = Head-> next;
        temp-> next = NULL;
        delete temp;
    }

    // Pop Back Function to pop element at the back.
    void popback(){
        if(Head == NULL){
            cout << "Empty Linked List." << endl;
            return;
        }
        Node* temp = Head;
        while(temp-> next != Tail){
            temp = temp-> next;
        }
        temp-> next = NULL;
        delete Tail;
        Tail = temp;
    }

    // Function to insert element at any position in Linked List.
    void insert(int val,int pos){
        Node* newnode = new Node(val);
        Node* temp = Head;
        if(pos < 0){
            cout << "Invalid Position." << endl;
            return;
        }

        if(pos == 0){
            pushfront(val);
            return;
        }

        for(int i = 0; i < pos - 1; i++){
            if(temp == NULL){
                cout << "Invalid Position." << endl;
                return;
        }
            temp = temp->next;
        }
        newnode-> next = temp->next;
        temp->next = newnode;
    }

    // Function to search for an element in Linked List.
    int search(int key){
        Node* temp = Head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // Function to print the Linked List.
    void printLL(){
        Node* temp = Head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp-> next;
        }
        cout << "NULL";
    }
};

int main(){
    List LL;
    LL.pushfront(4);
    LL.pushfront(3);
    LL.pushfront(2);
    LL.pushfront(1);

    LL.pushback(5);
    LL.pushback(6);
    LL.pushback(7);
    LL.pushback(8);

    LL.insert(3,3);

    cout << "Linked List before pop : ";
    LL.printLL();

    cout << "\nLinked List after pop : ";
    LL.popback();
    LL.popfront();

    LL.printLL();

    cout << endl;
    cout << LL.search(7) << endl;
}
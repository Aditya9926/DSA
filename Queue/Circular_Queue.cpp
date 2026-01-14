#include<iostream>
using namespace std;

class circularqueue{
    int* arr;
    int currsize, cap;
    int f,r; 
    public :

    circularqueue(int size){
        cap = size;
        arr = new int[cap];
        currsize = 0;
        f = 0;
        r = -1;
    }

    void push(int val){
        if(currsize == cap){
            cout << "Queue is full.";
            return;
        }
        else{
            r = (r+1) % cap;
            arr[r] = val;
            currsize++;
        }
    }

    void pop(){
        if(empty()){
            cout << "Queue is Empty.";
            return;
        }
        else{
            f = (f+1)%cap;
            currsize--;
        }
    }

    int front(){
        if(empty()){
            cout << "Queue is Empty.";
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currsize == 0;
    }

    void print(){
        for(int i=0; i<cap; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    circularqueue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.push(40);
    q.push(50);
    q.pop();
    q.print(); // Output : 10 20 30 40 50
    q.push(60); // Should succeed as one element was popped
    cout << "Front element: " << q.front() << endl; // Output: 30

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    } 
    return 0;
}
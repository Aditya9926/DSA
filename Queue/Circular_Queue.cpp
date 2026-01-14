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

    int print(){
        for(int i=0; i<currsize; i++){
            cout << arr[(f+i)%cap] << " ";
        }
    }
};

int main(){
    circularqueue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << endl; // Output: 10
    q.pop();
    cout << q.front() << endl; // Output: 20
    q.print(); // Output: 20 30
    return 0;
}
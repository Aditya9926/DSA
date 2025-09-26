#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> deq = {1,2,3}; // Declare and initialize Deque.

    // Push element in Deque.
    deq.push_back(4);
    deq.push_back(5);
    deq.emplace_back(6);

    deq.push_front(0);
    deq.push_front(-1);
    deq.emplace_front(-2);

    // Pop element in Deque.
    deq.pop_back();
    deq.pop_front();

    cout << "deq index 1 value : " << deq[1] << endl;

    cout << "Deque : ";
    for(int i : deq){
        cout << i << " ";
    }
    cout << endl;
}
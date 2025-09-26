#include<iostream>
#include<queue>
using namespace std;

int main (){
    priority_queue<int> pq; // Declaration and initialization of stack.
    
    pq.push(1); // Pushing elements onto the stack.
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.emplace(6);
    pq.emplace(70);
    pq.emplace(50);                           

    pq.pop(); // Removes the top element.

    cout << pq.top() << endl; // Prints the top element of the stack.
    cout << pq.size() << endl; // Prints the size of the stack.

    cout << "Priority Queue is : ";
    while(!pq.empty()){ // Loop until the stack is empty.
        cout << pq.top() << " "; // Print the top element of the stack.
        pq.pop(); // Remove the top element from the stack.
    }
    cout << endl;
    cout << pq.size() << endl; // Prints the size of stack s after swap.
    cout << pq.empty() << endl; // Checks if the stack is empty.
    
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(1); // Pushing elements onto the stack.
    pq2.push(2);
    pq2.push(3);
    pq2.push(4);
    pq2.push(5);
    pq2.emplace(6);
    pq2.emplace(70);
    pq2.emplace(50);

    pq2.pop(); // Removes the top element.

    cout << pq2.top() << endl; // Prints the top element of the stack.
    cout << pq2.size() << endl; // Prints the size of stack s2 after swap.

    cout << "Priority Queue 2 is : ";
    while(!pq2.empty()){ // Loop until the stack is empty.
        cout << pq2.top() << " "; // Print the top element of the stack.
        pq2.pop(); // Remove the top element from the stack.
    }
    cout << endl;

    return 0;
}
#include<iostream>
#include<queue>
using namespace std;

int main (){
    queue<int> q; // Declaration and initialization of queue.
    
    q.push(1); // Pushing elements onto the queue.
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.emplace(6);
    q.emplace(70);
    q.emplace(50);                           

    q.pop(); // Removes the top element.

    cout << q.size() << endl; // Prints the size of the stack.

    queue<int> q2;
    q2.swap(q); // Swaps the contents of stack s2 with stack s.

    cout << q.size() << endl; // Prints the size of stack s after swap.
    cout << q2.size() << endl; // Prints the size of stack s2 after swap.

    cout << "Queue 2 is : ";
    while(!q2.empty()){ // Loop until the stack is empty.
        cout << q2.front() << " "; // Print the top element of the stack.
        q2.pop(); // Remove the top element from the stack.
    }
    cout << endl;

    cout << q.empty(); // Checks if the stack is empty.

    return 0;
}
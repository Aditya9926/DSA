#include<iostream>
#include<stack>
using namespace std;

int main (){
    stack<int> s; // Declaration and initialization of stack.
    
    s.push(1); // Pushing elements onto the stack.
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.emplace(6);
    s.emplace(70);
    s.emplace(50);                           

    s.pop(); // Removes the top element.

    cout << s.top() << endl; // Prints the top element of the stack.
    cout << s.size() << endl; // Prints the size of the stack.

    stack<int> s2;
    s2.swap(s); // Swaps the contents of stack s2 with stack s.

    cout << s.size() << endl; // Prints the size of stack s after swap.
    cout << s2.size() << endl; // Prints the size of stack s2 after swap.

    cout << "Stace 2 is : ";
    while(!s2.empty()){ // Loop until the stack is empty.
        cout << s2.top() << " "; // Print the top element of the stack.
        s2.pop(); // Remove the top element from the stack.
    }
    cout << endl;

    cout << s.empty(); // Checks if the stack is empty.

    return 0;
}
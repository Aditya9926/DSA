#include<iostream>
#include<queue>
#include<deque>
using namespace std;

int main(){
    queue<int> q;
    deque<int> d;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10

    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // 20

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // No

    cout << "Size of queue: " << q.size() << endl; // 2

    d.push_back(100);
    d.push_back(200);
    d.push_front(50);
    cout << "Front element of deque: " << d.front() << endl; // 50
    cout << "Back element of deque: " << d.back() << endl; // 200
    d.pop_front();
    cout << "Front element of deque after pop_front: " << d.front() << endl; // 100

    return 0;
}
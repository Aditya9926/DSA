#include<iostream>
#include<stack>
using namespace std;

class solution{
    public :
    stack<int> s1;
    stack<int> s2;

    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop(){
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek(){
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};

int main(){
    solution q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.peek()<<endl; // 1
    cout<<q.pop()<<endl; // 1
    cout<<q.empty()<<endl; // 0 (false)
    return 0;
}
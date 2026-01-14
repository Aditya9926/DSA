#include<iostream>
#include<queue>
using namespace std;

class solution{
    public : 
    queue<int> q1;
    queue<int> q2;

    void push(int x){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

int main(){
    solution st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl; // 3
    cout<<st.pop()<<endl; // 3
    cout<<st.empty()<<endl; // 0 (false)
    return 0;
}
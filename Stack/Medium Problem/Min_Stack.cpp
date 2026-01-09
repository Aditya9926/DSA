#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution1{
    public :
    stack<pair<int,int>> s;
    void push(int val){
        if(s.empty()){
            s.push({val,val});
        }
        else{
            int minval = min(val,s.top().second);
            s.push({val,minval});
        }
    }

    void pop(){
        s.pop();
    }

    int top(){
        return s.top().first;
    }

    int getmin(){
        return s.top().second;
    }
};

int main(){
    Solution1 st;
    st.push(3);
    st.push(5);
    cout<<st.getmin()<<endl; // 3
    st.push(2);
    st.push(1);
    cout<<st.getmin()<<endl; // 1
    st.pop();
    cout<<st.getmin()<<endl; // 2
    st.pop();
    cout<<st.top()<<endl;    // 5
    cout<<st.getmin()<<endl; // 3
    return 0;
}
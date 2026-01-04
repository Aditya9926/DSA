#include<iostream>
#include<vector>
using namespace std;

class stack{
    vector<int> v;
    public :
    void push(int val){
        v.push_back(val);
    }

    void pop(){
        v.pop_back();
    }

    int top(){
        return v[v.size() - 1];
    }

    bool empty(){
        return v.size() == 0;
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(6);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
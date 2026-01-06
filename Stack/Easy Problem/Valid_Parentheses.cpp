#include<iostream>
#include<stack>

using namespace std;

class Solution{
    public : 
    bool isvalid(string str){
        stack<char> s;
        int n = str.size();
        for(int i = 0; i < n; i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                s.push(str[i]);
            }
            else{
                if(s.size() == 0){
                    return false;
                }
                if((s.top() == '(' && str[i] == ')') || (s.top() == '[' && str[i] == ']') || (s.top() == '{' && str[i] == '}') ){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
        return s.size() == 0;
    }
};

int main(){
    string str = "()[]{}";
    Solution obj;
    if(obj.isvalid(str)){
        cout<<"Valid Parentheses"<<endl;
    }
    else{
        cout<<"Invalid Parentheses"<<endl;
    }
    return 0;
}
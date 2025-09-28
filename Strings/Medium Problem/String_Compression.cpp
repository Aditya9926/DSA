#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& c) {
        int n = c.size();
        int idx = 0;
        for(int i = 0; i < n; i++){
            char ch = c[i];
            int count = 0;
            while(i < n && c[i] == ch){
                count ++, i++;
            } 
            if(count == 1){
                c[idx++] = ch;
            }
            else{
                c[idx++] = ch;
                string str = to_string(count);
                for(char h : str){
                    c[idx++] = h; 
                }
            }
            i--;
        }
        c.resize(idx);
        return idx;
    }
};

int main (){
    Solution sol;
    vector<char> c = {'a','a','b','b','c','c','c'};
    int ans = sol.compress(c);
    cout << ans << endl;
    for(char ch : c){
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}
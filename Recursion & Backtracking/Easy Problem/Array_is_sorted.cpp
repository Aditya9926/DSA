#include<iostream>
#include<vector>
using namespace std;

bool issorted(vector<int> n, int s){
    if(s == 0 || s == 1){
        return true;
    }
    return n[s-1] >= n[s-2] && issorted(n, s-1);
}

int main(){
    vector<int> arr = {1,2,8,4,5};
    int n = arr.size();
    cout << issorted(arr,n);
}
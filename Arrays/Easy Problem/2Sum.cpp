#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 2Sum using Hashing.
vector<int> twosum(vector<int> &arr, int tar){
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++){
        int f = arr[i];
        int s = tar - f;
        if(m.find(s) != m.end()){
            ans.push_back(i);
            ans.push_back(m[s]);
            break;
        }
        m[f] = i;
    }
    return ans;
}

int main(){
    vector<int> arr = {2,7,11,15};
    int tar = 9;
    cout << "The index is: ";
    vector<int> res = twosum(arr, tar); 
    cout << res[0] << "," << res[1] << endl;
    return 0;
}
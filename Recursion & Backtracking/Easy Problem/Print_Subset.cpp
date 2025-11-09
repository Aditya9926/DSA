#include<iostream>
#include<vector>
using namespace std;

void prisub(vector<int>& arr,vector<int>& res, int i){
    if(i == arr.size()){
        for(int j = 0; j < res.size(); j++){
            cout << res[j] << " ";
        }
        cout << endl;
        return;
    }
    // Inclusion
    res.push_back(arr[i]); 
    prisub(arr,res,i+1);

    //Exclusion
    res.pop_back(); //Backtracking
    prisub(arr,res,i+1);
}

int main(){
    vector<int> arr = {1,2,3};
    vector<int> ans;
    prisub(arr,ans,0);
    return 0;
}
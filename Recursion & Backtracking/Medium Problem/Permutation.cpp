#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getpermute(vector<int>& nums,int idx, vector<vector<int>>& ans){
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = idx; i < nums.size(); i++){
        swap(nums[idx], nums[i]);
        getpermute(nums,idx+1,ans);
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    getpermute(nums,0,ans);
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> res = permute(arr);
    for(auto num : res){
        cout << "[ ";
        for(auto nums : num){
            cout << nums << " ";
        }
        cout << "]" << endl;
    }
}
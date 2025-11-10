#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getsubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubsets){
    if(i == nums.size()){
        allsubsets.push_back({ans});
        return;
    }
    // Inclusion.
    ans.push_back(nums[i]);
    getsubsets(nums,ans,i+1,allsubsets);
    
    // Exclusion.
    ans.pop_back();
    int idx = i + 1;
    while(idx < nums.size() && nums[idx] == nums[idx - 1]){
        idx++;
    }
    getsubsets(nums,ans,idx,allsubsets);
}

vector<vector<int>> subset(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> allsubset;
    vector<int> ans;
    getsubsets(nums,ans,0,allsubset);
    return allsubset;
}

int main(){
    vector<int> arr = {1,2,2};
    vector<vector<int>> res = subset(arr);
    for(auto i : res){
        cout << "[ ";
        for(auto num : i){
            cout << num << " ";
        }
        cout << "]" << endl;
    }
}
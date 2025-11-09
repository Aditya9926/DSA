#include <iostream>
#include <vector>
using namespace std;

void getsubsets(vector<int> &arr, vector<int> &ans, int i,vector<vector<int>> &allsub)
{
    if(i == arr.size()){
        allsub.push_back({ans});
        return;
    }
    ans.push_back(arr[i]);
    getsubsets(arr,ans,i+1,allsub);

    ans.pop_back();
    getsubsets(arr,ans,i+1,allsub);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> allsub;
    vector<int> ans;
    getsubsets(nums,ans,0,allsub);
    return allsub;
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> result = subsets(arr);
    for(auto subset : result){
        cout << "[ ";
        for(auto num : subset){
            cout << num << " ";
        }
        cout << "]" << endl;
    }
}
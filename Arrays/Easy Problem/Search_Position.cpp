#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n  = nums.size()-1;
        int result;
    
        for(int i =0 ;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
            else if(nums[n]<target){
                 return n+1;
            }
            else if(nums[i]>target){
                 return 0;
            }
            else if(nums[i]<target && target<nums[i+1]){
                return i+1;
            }
            

        }
      return result;
    }
};

int main(){
    vector<int> arr = {1,3,5,6};
    int tar = 5;
    Solution sol;
    int result = sol.searchInsert(arr,tar);
    cout << result << endl;
}
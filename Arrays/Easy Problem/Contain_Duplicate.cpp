#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> numCountMap;

        for(auto num : nums)
        {
            if(numCountMap.find(num)!=numCountMap.end())
                return true;
            
            numCountMap[num]++;
        }

        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout<<sol.containsDuplicate(nums)<<endl;
    return 0;
}
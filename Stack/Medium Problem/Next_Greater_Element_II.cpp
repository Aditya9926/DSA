#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
    public :
    vector<int> nextGreaterElements(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n,0);
        stack<int> s;

        for(int i = 2*n-1; i >= 0; i--){
            while(s.size() > 0 && nums[s.top()] <= nums[i%n]){
                s.pop();
            }
            ans[i%n] = s.empty() ? -1 : nums[s.top()];

            s.push(i%n);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1};
    vector<int> result = sol.nextGreaterElements(nums);
    cout << "Next Greater Elements: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int i=0;
        int j=0;
        unordered_map<long long, unordered_map<int, int>> m;
        int count = 0;
        while(j<n) {
            while(i!=j) {
                long long diff = 1LL * nums[j]-nums[i];
                m[diff][j] += 1 + m[diff][i];
                count += m[diff][i];
                i++;
            }
            i=0;
            j++;
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,4,6,8,10};
    cout<<s.numberOfArithmeticSlices(nums);
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // Optimized: Proper DP approach without nested loop resets
    // Time complexity: O(n^2) instead of O(n^3)
    // dp[i][diff] = number of arithmetic subsequences ending at index i with difference diff
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;

        // dp[i] maps difference -> count of subsequences ending at index i
        vector<unordered_map<long long, int>> dp(n);
        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];

                // Count of subsequences ending at j with this difference
                int count_at_j = dp[j].count(diff) ? dp[j][diff] : 0;

                // Add to result: all subsequences ending at j can be extended to i
                result += count_at_j;

                // Update dp[i][diff]: includes all extended subsequences plus new pair (j, i)
                dp[i][diff] += count_at_j + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,4,6,8,10};
    cout << "Arithmetic Slices: " << s.numberOfArithmeticSlices(nums) << endl;

    // Test with more examples
    vector<int> nums2 = {7,7,7,7,7};
    cout << "Arithmetic Slices: " << s.numberOfArithmeticSlices(nums2) << endl;

    return 0;
}
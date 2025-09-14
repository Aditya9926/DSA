#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int str = 0;
        int end = n - 1;
        while (str <= end) {
            int mid = (str + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[str] <= nums[mid]) {
                if (nums[str] <= target && target <= nums[mid]) {
                    end = mid - 1;

                } else {
                    str = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[end]) {
                    str = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int tar = 0;
    Solution sol;
    int result = sol.search(arr,tar);
    cout <<"The target is at index : " << result << endl;
}
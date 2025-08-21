#include <iostream>
#include <vector>
using namespace std;

// Function to find Majority Element using Brute Force
int findMajorityElement(const vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count > n / 2) {
            return nums[i];
        }
    }
    return -1; // No majority element found
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int majorityElement = findMajorityElement(nums);
    if (majorityElement != -1) {
        cout << "Majority Element: " << majorityElement << endl;
    } else {
        cout << "No Majority Element found." << endl;
    }
    return 0;
}

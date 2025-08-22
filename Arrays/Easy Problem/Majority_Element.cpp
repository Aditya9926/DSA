#include <iostream>
#include <vector>
#include <algorithm>
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
    return -1; 
}

// Function to find Majority Element using sorting
int findMajorityElementSorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count = 1, majorityCount = nums.size() / 2;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1]) {
            count++;
            if (count > majorityCount) {
                return nums[i];
            }
        } else {
            count = 1;
        }
    }
}

// Function to find Majority Element using Boyer-Moore Voting Algorithm
int findMajorityElementBoyerMoore(const vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    // Verify if the candidate is actually the majority element
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }
    
    return (count > nums.size() / 2) ? candidate : -1;
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};

    int majorityElement = findMajorityElement(nums);

    if (majorityElement != -1) {
        cout << "Majority Element: " << majorityElement << endl;
    } 
    
    else {
        cout << "No Majority Element found." << endl;
    }

    majorityElement = findMajorityElementSorting(nums);

    if (majorityElement != -1) {
        cout << "Majority Element (Sorting): " << majorityElement << endl;
    } 
    
    else {
        cout << "No Majority Element found using sorting." << endl;
    }

    majorityElement = findMajorityElementBoyerMoore(nums);

    if (majorityElement != -1) {
        cout << "Majority Element (Boyer-Moore): " << majorityElement << endl;
    } 
    
    else {
        cout << "No Majority Element found using Boyer-Moore." << endl;
    }

    return 0;
}

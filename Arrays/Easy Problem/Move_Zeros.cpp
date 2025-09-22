#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};

int main(){
    vector<int> arr = {0,1,0,3,12};
    cout << "Array before moving zeros : ";
    for(int i : arr){
        cout << i << " ";
    }
    Solution sol;
    sol.moveZeroes(arr);
    cout << "\nArray after moving zeros : ";
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}
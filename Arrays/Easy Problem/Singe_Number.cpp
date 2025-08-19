#include <iostream>
#include <vector>
using namespace std;

int singlenumber(vector<int>& nums){
    int ans  = 0;
    for(int i : nums){
        ans ^= i;
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The given array is: ";
    for (int i : nums) {
        cout << i << "  ";
    }
    cout << endl << "The single number is: " << singlenumber(nums) << endl;
    return 0;
}
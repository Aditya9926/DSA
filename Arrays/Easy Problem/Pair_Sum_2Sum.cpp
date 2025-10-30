#include <iostream>
#include <vector>
using namespace std;

// Function to find if there exists a pair with a given sum using brute force
vector<int> PairSumBF(vector<int>& arr, int targetSum) {
    vector<int> ans;
    int count = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == targetSum) {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                return ans;
            }
        }
    }
    return ans;
}

// Function to find if there exists a pair with a given sum using an optimized approach
vector<int> PairSum(const vector<int>& arr, int targetSum){
    int n = arr.size();
    vector<int> ans;
    int i = 0,j = n-1;
    while (i < j)
    {
        int pairSum = arr[i] + arr[j];
        if (pairSum == targetSum) {
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            return ans;
        } else if (pairSum < targetSum) {
            i++; 
        } else {
            j--; 
        }
    }
    
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int targetSum = 5;

    // Using brute force method
    vector<int> resultBF = PairSumBF(arr, targetSum);
    if (!resultBF.empty()) {
        cout << "Pair found using brute force: " << resultBF[0] << ", " << resultBF[1] << endl;
    } else {
        cout << "No pair found using brute force." << endl;
    }

    // Using optimized method
    vector<int> result = PairSum(arr, targetSum);
    if (!result.empty()) {
        cout << "Pair found using optimized method: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No pair found using optimized method." << endl;
    }
    return 0;
}
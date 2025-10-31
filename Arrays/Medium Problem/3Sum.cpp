#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

// Brute Force Approach O(n^3) - Not Efficient.
vector<vector<int>> threesumbru(vector<int> &arr){
    set<vector<int>> s;
    vector<vector<int>> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> triplit = {arr[i], arr[j], arr[k]};
                    sort(triplit.begin(),triplit.end());
                    if(s.find(triplit) == s.end()){
                        s.insert(triplit);
                        ans.push_back(triplit);
                    }
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            long long sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> resultbru = threesumbru(nums);
    vector<vector<int>> result = threeSum(nums);
    for (const auto &triplet : result)
    {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i)
        {
            cout << triplet[i];
            if (i < triplet.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    for (const auto &tri : resultbru)
    {
        cout << "[";
        for (size_t i = 0; i < tri.size(); ++i)
        {
            cout << tri[i];
            if (i < tri.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;
}
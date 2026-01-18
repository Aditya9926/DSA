#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for (int i = k; i < arr.size(); i++)
        {
            ans.push_back(arr[dq.front()]);

            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(arr[dq.front()]);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(arr, k);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}
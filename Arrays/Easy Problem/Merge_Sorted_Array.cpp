#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 1st Approach
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

    // 2nd Approach
    void mergeAC(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int idx = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
            {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            }
            else
            {
                nums1[idx] = nums2[j];
                idx--;
                j--;
            }
        }
        while (j >= 0)
        {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }
};

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};
    int m = 3, n = 3;
    Solution sol;
    sol.merge(arr1, m, arr2, n);
    cout << "Merge Sorting using 1st Approach : ";
    for (int num : arr1)
    {
        cout << num << " ";
    }
    cout << endl;

    sol.mergeAC(arr1, m, arr2, n);
    cout << "Merge Sorting using 2st Approach : ";
    for (int no : arr1)
    {
        cout << no << " ";
    }
    cout << endl;
}
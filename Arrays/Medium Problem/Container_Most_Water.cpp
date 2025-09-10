#include <vector>
#include <iostream>
using namespace std;

// Using Brute force method 
int maxwater(vector<int> &arr)
{
    int n = arr.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int w = j-i;
            int ht = min(arr[i], arr[j]);
            int amount = w*ht;
            res = max(amount, res);
        }
    }
    return res;
}

// Optimal Solution (2 pointer approach)
int maxWater(vector<int> &arr) {
  	int left = 0, right = arr.size() - 1;
    int res = 0;
    while(left < right) {
        int water = min(arr[left], arr[right]) * (right - left);
        res = max(res, water);
      
        if(arr[left] < arr[right])
            left += 1;
        else
            right -= 1;
    }
  
    return res;
}

int main()
{
    vector<int> arr = {2, 1, 8, 6, 4, 6, 5, 5};
    cout << "Water stored in container using brute force method : "<< maxwater(arr);
    cout << "\nWater stored in container using Optimal method : "<< maxWater(arr);
}
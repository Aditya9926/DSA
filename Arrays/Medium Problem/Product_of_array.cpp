#include <iostream>
#include <vector>
using namespace std;

// using brute force method
vector<int> productarry(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                ans[i] *= arr[j];
            }
        }
    }
    return ans;
}

// optimal solution
vector<int> productarryop(vector<int> &arr)
{
    int n = arr.size();
    vector<int> sol(n, 1);
    vector<int> pre(n, 1);
    vector<int> sur(n, 1);
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] * arr[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        sur[i] = sur[i + 1] * arr[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        sol[i] = pre[i] * sur[i];
    }
    return sol;
}

// Using Space Complexity
vector<int> productarrysc(vector<int> &arr)
{
    int n = arr.size();
    int sur = 1;
    vector<int> sna(n, 1);
    for (int i = 1; i < n; i++)
    {
        sna[i] = sna[i - 1] * arr[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        sur *= arr[i + 1];
        sna[i] *= sur;
    }
    return sna;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> ans = productarry(arr);
    vector<int> sol = productarryop(arr);
    vector<int> sna = productarrysc(arr);
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << "\n";
    for (int val : sol)
    {
        cout << val << " ";
    }
    cout << "\n";
    for (int val : sna)
    {
        cout << val << " ";
    }
    return 0;
}
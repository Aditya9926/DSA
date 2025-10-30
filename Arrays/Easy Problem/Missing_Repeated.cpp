#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> MAR(vector<vector<int>> &grid)
{
    vector<int> ans;
    unordered_set<int> m;
    int n = grid.size();
    int a, b, ex_s = 0, ac_s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ac_s += grid[i][j];
            if (m.find(grid[i][j]) != m.end())
            {
                a = grid[i][j];
                ans.push_back(a);
            }
            m.insert(grid[i][j]);
        }
    }
    ex_s = (n * n) * (n * n + 1) / 2;
    b = ex_s + a - ac_s;
    ans.push_back(b);
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> result = MAR(grid);
    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}
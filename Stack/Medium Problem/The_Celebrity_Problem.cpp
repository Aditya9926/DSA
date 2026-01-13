#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int getcelebrity(vector<vector<int>> arr)
    {
        stack<int> s;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {
            int i = s.top();
            s.pop();

            int j = s.top();
            s.pop();

            if (arr[i][j] == 0)
            {
                s.push(i);
            }
            else
            {
                s.push(j);
            }
        }

        int celeb = s.top();
        for(int i = 0; i < n; i++){
            if(i != celeb && arr[i][celeb] == 0 || arr[celeb][i] == 1){
                return -1;
            }
        }
        return celeb;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};
    int celeb = sol.getcelebrity(arr);
    if (celeb == -1)
    {
        cout << "No Celebrity Present" << endl;
    }
    else
    {
        cout << "Celebrity is at index: " << celeb << endl;
    }
    return 0;   
}
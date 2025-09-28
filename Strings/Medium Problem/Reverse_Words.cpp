#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++)
        {
            string sw = "";
            while (i < n && s[i] != ' ')
            {
                sw += s[i];
                i++;
            }
            reverse(sw.begin(), sw.end());
            if (sw.length() > 0)
            {
                ans += " " + sw;
            }
        }
        return ans.substr(1);
    }
};

int main()
{
    string s = "the sky   is blue";
    Solution obj;
    cout << obj.reverseWords(s);
    return 0;
}
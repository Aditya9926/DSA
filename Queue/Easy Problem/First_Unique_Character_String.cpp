#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int firstchar(string s)
    {
        queue<int> q;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }
            m[s[i]] ++;

            while(q.size() > 0 && m[s[q.front()]] > 1){
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};

int main()
{
    Solution sol;
    string s = "leetcode";
    cout << "The index of the first unique character in \"" << s << "\" is: " << sol.firstchar(s) << endl;

    s = "loveleetcode";
    cout << "The index of the first unique character in \"" << s << "\" is: " << sol.firstchar(s) << endl;

    s = "aabb";
    cout << "The index of the first unique character in \"" << s << "\" is: " << sol.firstchar(s) << endl;

    return 0;
}
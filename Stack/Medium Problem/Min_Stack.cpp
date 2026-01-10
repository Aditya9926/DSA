#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution1
{
public:
    stack<long long int> s;
    long long int minval;
    Solution1()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            minval = val;
        }
        else
        {
            if (val < minval)
            {
                s.push((long long)2 * val - minval);
                minval = val;
            }
            else
            {
                s.push(val);
            }
        }
    }

    void pop()
    {
        if (s.top() < minval)
        {
            minval = 2 * minval - s.top();
        }
        s.pop();
    }

    int top()
    {
        if (s.top() < minval)
        {
            return minval;
        }
        else
        {
            return s.top();
        }
    }

    int getMin()
    {
        return minval;
    }
};

class Solution2
{
public:
    stack<pair<int, int>> s;
    void push(int val)
    {
        if (s.empty())
        {
            s.push({val, val});
        }
        else
        {
            int minval = min(val, s.top().second);
            s.push({val, minval});
        }
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getmin()
    {
        return s.top().second;
    }
};

int main()
{
    Solution1 ms;
    cout << "Using Solution1" << endl;
    ms.push(3);
    ms.push(5);
    cout << ms.getMin() << endl; // 3
    ms.push(2);
    ms.push(1);
    cout << ms.getMin() << endl; // 1
    ms.pop();
    cout << ms.getMin() << endl; // 2
    ms.pop();
    cout << ms.top() << endl;    // 5
    cout << ms.getMin() << endl; // 3
    cout << "Using Solution2" << endl;

    Solution2 st;
    st.push(3);
    st.push(5);
    cout << st.getmin() << endl; // 3
    st.push(2);
    st.push(1);
    cout << st.getmin() << endl; // 1
    st.pop();
    cout << st.getmin() << endl; // 2
    st.pop();
    cout << st.top() << endl;    // 5
    cout << st.getmin() << endl; // 3
    return 0;
}
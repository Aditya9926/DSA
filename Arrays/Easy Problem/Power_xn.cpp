#include <iostream>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        double half = myPow(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};

int main()
{
    Solution sol;
    double x = 2;
    int n = 10;
    cout << "Result: " << sol.myPow(x, n) << endl;
    return 0;
}
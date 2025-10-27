#include <iostream>
#include<limits.h>
using namespace std;

int rev(int a)
{
    int ans = 0;
    while (a != 0)
    {
        int b = a % 10;
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
        {
            return 0;
        }
        ans = ans * 10 + b;
        a = a / 10;
    }
    return ans;
}

int main()
{
    int a;
    cout << "Enter a number : ";
    cin >> a;
    cout << "Reverse of number is : " << rev(a);
}
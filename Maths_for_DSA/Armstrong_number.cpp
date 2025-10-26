#include <iostream>
using namespace std;

int armstrong(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int dig = n % 10;
        sum += (dig * dig * dig);
        n = n / 10;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    if(armstrong(n) == n){
        cout << n << " is an armstrong number.";
    }
    else{
        cout << n << " is not an armstrong number.";
    }
}
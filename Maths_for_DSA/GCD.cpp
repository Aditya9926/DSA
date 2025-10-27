#include <iostream>
using namespace std;

// Using Euclid's algorithm.
int Euclidalgo(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    if (a == 0){
        return b;
    }
    else{
        return a;
    }
}

// Using recursion.
int rec(int a , int b){
    if(b == 0){
        return a;
    }
    return rec(b,a%b);
}

int main()
{
    int a, b;
    cout << "Enter First Number : ";
    cin >> a;
    cout << "Enter Second Number : ";
    cin >> b;
    int gcd = 1;

    // Simple Approach.
    for (int i = 1; i <= min(a, b); i++)
    {
        if (a == 0 && b == 0)
        {
            gcd = 0;
        }
        else if (a == b)
        {
            gcd = a;
        }
        else if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    cout << "Greater Common Divisor is : " << gcd;
    cout << "\nGreater common Divisor using Euclid algorithm is : " << Euclidalgo(a,b);
    cout << "\nGreater common Divisor using recursion is : " << rec(a,b);
}
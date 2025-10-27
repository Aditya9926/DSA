#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    if(a == 0){
        return b;
    }
    else{
        return a;
    }
}

int main(){
    int a,b,lcm;
    cout << "Enter First number : ";
    cin >> a;
    cout << "Enter Second number : ";
    cin >> b;
    lcm = (a*b)/ gcd(a,b);
    cout << "Lowest common factor is : " << lcm << endl;
}
#include<iostream>
using namespace std;

void numdigit(int n){
    while(n != 0){
        int digi = n%10;
        cout << digi << " ";
        n = n/10;
    }
}

int main(){
    int n;
    cout << "Enter a digit : ";
    cin >> n;
    numdigit(n);
}
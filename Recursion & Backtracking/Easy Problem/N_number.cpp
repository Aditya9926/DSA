#include<iostream>
using namespace std;

int num(int n){
    if(n == 0){
        return 0;
    }
    cout << n << ", ";
    return num(n - 1);
}

int main(){
    int n = 10;
    num(n);
    return 0;
}
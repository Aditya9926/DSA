#include<iostream>
#include<vector>
using namespace std;

// Simple prime number code.
string isprime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return "not a prime number.";
        }
    }
    return "prime number.";
}

// Sieve of Eratosthenes.f
int countprime(int n){
    vector<bool> ispri(n+1,true);
    int count = 0;
    for(int i = 2; i<n; i++){
        if(ispri[i]){
            count ++;
            for(int j = i*2; j < n; j = j+i){
                ispri[j] = false;
            }
        }
    }
    return count;
}

int main (){
    int n,N;
    cout << "Enter a number to check for prime : ";
    cin >> n;
    cout << "Enter a range to check prime numbers : ";
    cin >> N;
    cout << isprime(n) << endl;
    cout << countprime(N) << endl;
}
#include<iostream>
#include<vector>
using namespace std;

// Optimized: Using memoization to avoid exponential time complexity
// Time complexity: O(n) instead of O(2^n)
// Space complexity: O(n) for memoization array
int fibMemo(int n, vector<int>& memo){
    if(n == 0 || n == 1){
        return n;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
    return memo[n];
}

int fib(int n){
    vector<int> memo(n+1, -1);
    return fibMemo(n, memo);
}

// Alternative: Iterative approach with O(1) space
int fibIterative(int n){
    if(n == 0 || n == 1){
        return n;
    }
    int prev1 = 1, prev2 = 0;
    for(int i = 2; i <= n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n = 6;
    cout << "Fibonacci(" << n << ") using memoization: " << fib(n) << endl;
    cout << "Fibonacci(" << n << ") using iterative: " << fibIterative(n) << endl;

    // Test with larger number to show performance difference
    n = 40;
    cout << "Fibonacci(" << n << ") using memoization: " << fib(n) << endl;
    cout << "Fibonacci(" << n << ") using iterative: " << fibIterative(n) << endl;
    return 0;
}
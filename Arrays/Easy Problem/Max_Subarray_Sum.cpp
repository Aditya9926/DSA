#include <iostream>
using namespace std;

// Function to find the Maximus Sub Array Sum using Brute Force approach
int Brute(int arr[], int n) {
    int maxSum = arr[0];
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}
 
// Function to find the Maximus Sub Array Sum using Kadane's Algorithm
int Kadane(int arr[], int n) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    
    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Max Subarray Sum using Brute Force: " << Brute(arr, n) << endl;
    cout << "Max Subarray Sum using Kadane's Algorithm: " << Kadane(arr, n) << endl;
    
    return 0;
}
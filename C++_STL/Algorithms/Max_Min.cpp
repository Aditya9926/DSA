#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main (){
    int arr[5] = {5,4,3,2,1}; // Array of 5 integers.
    int n = sizeof(arr)/sizeof(arr[0]);

    // Finding the maximum element in the array
    int maxElement = *max_element(arr, arr+n);
    cout << "Maximum element in the array: " << maxElement << endl;

    // Finding the minimum element in the array
    int minElement = *min_element(arr, arr+n);
    cout << "Minimum element in the array: " << minElement << endl;

    vector<int> vec = {5,4,3,2,1}; // Vector of integers.
    // Finding the maximum element in the vector
    int maxVecElement = *max_element(vec.begin(), vec.end());
    cout << "Maximum element in the vector: " << maxVecElement << endl;
    
    // Finding the minimum element in the vector
    int minVecElement = *min_element(vec.begin(), vec.end());
    cout << "Minimum element in the vector: " << minVecElement << endl;    

    return 0;
}
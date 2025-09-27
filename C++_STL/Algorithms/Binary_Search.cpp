#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // Array of 5 integers.
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3; // Element to search for.

    // Performing binary search on the array
    bool found = binary_search(arr, arr + n, target);
    if (found)
        cout << target << " found in the array." << endl;
    else
        cout << target << " not found in the array." << endl;

    vector<int> vec = {1, 2, 3, 4, 5}; // Vector of integers.
    // Performing binary search on the vector
    found = binary_search(vec.begin(), vec.end(), target);
    if (found)
        cout << target << " found in the vector." << endl;
    else
        cout << target << " not found in the vector." << endl;

    return 0;
}
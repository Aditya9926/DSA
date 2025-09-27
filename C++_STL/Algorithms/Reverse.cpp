#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main (){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, arr+n); // Reversing the array
    cout << "Reversed array: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    vector<int> vec = {1, 2, 3, 4, 5};
    reverse(vec.begin(), vec.end()); // Reversing the vector
    cout << "Reversed vector: ";
    for(int v : vec)
        cout << v << " ";
    cout << endl;

    reverse(vec.begin()+1, vec.end()-1); // Reversing a subrange of the vector
    cout << "Partially reversed vector: ";
    for(int v : vec)
        cout << v << " ";
    cout << endl;
}
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec = {1,2,3,4,5}; // Declare and initialize vector.

    cout << "vec.begin : " << *(vec.begin()) << endl; // Insert 10 at index 1. O(n) operation.
    cout << "vec.end : " << *(vec.end()) << endl; // Insert 10 at index 1. O(n) operation.
    cout << "vec.end - 1 : " << *(vec.end() - 1) << endl; // Insert 10 at index 1. O(n) operation.

    cout << "Vector : ";
    for(int i : vec){
        cout  << i << " ";
    }
    cout << endl;
}
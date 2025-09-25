#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec = {1,2,3,4,5}; // Declare and initialize vector.

    vector <int>::iterator itr; // Iterator.
    for(itr = vec.begin(); itr != vec.end(); itr++){
        cout << *itr << " "; // Dereference iterator to get value.
    }
    cout << endl;

    vector <int>::reverse_iterator ritr; // Reverse iterator.
    for(ritr = vec.rbegin(); ritr != vec.rend(); ritr++){
        cout << *ritr << " "; // Dereference iterator to get value.
    }
    cout << endl;

    for(auto it = vec.begin(); it != vec.end(); it++){ // Using auto keyword.
        cout << *it << " "; // Dereference iterator to get value.
    }
    cout << endl;

    for(auto it = vec.rbegin(); it != vec.rend(); it++){ // Using auto keyword.
        cout << *it << " "; // Dereference iterator to get value.
    }

    cout << "vec.begin : " << *(vec.begin()) << endl; // Insert 10 at index 1. O(n) operation.
    cout << "vec.end : " << *(vec.end()) << endl; // Insert 10 at index 1. O(n) operation.
    cout << "vec.end - 1 : " << *(vec.end() - 1) << endl; // Insert 10 at index 1. O(n) operation.

    cout << "Vector : ";
    for(int i : vec){
        cout  << i << " ";
    }
    cout << endl;
}
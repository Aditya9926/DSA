#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1 = {10,20,30,40,50}; // Declare and initialize vector.

    vec1.clear(); // Clear all elements of vector.

    cout << "Vector is empty or not : " << vec1.empty() << endl; // Check whether vector is empty or not.
    
    cout << "Vector 1 size after clear : " << vec1.size() << endl; // Tell the size of array.

    cout << "Vector 1 capacity after clear : " << vec1.capacity() << endl; // Tell the capacity required to make new array.

    vector<int> vec = {1,2,3,4,5,6,7,8,9,10}; // Declare and initialize vector.

    vec.erase(vec.begin()); // Erase element at beginning of vector.
    vec.erase(vec.begin()+3); // Erase element at index 3 of vector.
    vec.erase(vec.begin()+1,vec.begin()+3); // Erase elements from index 1 to index 3 (3 not included).

    vec.insert(vec.begin(),0); // Insert 0 at beginning of vector.
    vec.insert(vec.begin()+1,2,1); // Insert two 100 at index 1 of vector.

    cout << "Vector : ";
    for(int i : vec){
        cout  << i << " ";
    }
    cout << endl;
}
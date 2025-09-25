#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec = {10,20}; // Declare and initialize vector.

    vector<int> vec1(5,100); // Declare vector of size 5 and initialize all elements with 100.

    vector<int> vec2(vec); // Declare vector and copy all elements of vec in vec2.


    vec.push_back(30); // Push an element in vector.
    vec.push_back(40);

    vec.emplace_back(50); // Push an element in vector.
    vec.emplace_back(60);
    
    vec.pop_back(); // Delete last element of the vector.

    cout << "Vector : ";
    for(int i : vec){
        cout  << i << " ";
    }
    cout << endl;

    cout << "Vector at index 2 : " << vec[2] << " OR " << vec.at(2) << endl; // vector at particular index using indexing and "at".

    cout << "Size of vector is : " << vec.size() << endl; // Tell the size of array.

    cout << "Capacity of vector is : " << vec.capacity() << endl; // Tell the capacity required to make new array.

    cout << "Vector front element is : " << vec.front() << endl;
    
    cout << "Vector End element is : " << vec.back() << endl;

    cout << "Vector 1 : ";
    for(int i : vec1){
        cout << i << " ";
    }
    cout << endl;

    cout << "Vector 2 : ";
    for(int i : vec2){
        cout << i << " ";
    }
    cout << endl;
}
#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(1); // Push an element in vector.
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    cout << "Vector : ";
    for(int i : vec){
        cout  << i << " ";
    }
    cout << endl;
    cout << "Size of vector is : " << vec.size() << endl; // Tell the size of array.
    cout << "Capacity of vector is : " << vec.capacity() << endl; // Tell the capacity required to make new array.
}
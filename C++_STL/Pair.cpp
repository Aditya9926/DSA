#include<iostream>
#include<vector>
using namespace std;

int main (){
    pair<int, int> p = {10 , 20}; // Declare and initialize Pair of int data type.
    cout << p.first << endl;
    cout << p.second << endl;
    cout << endl;

    pair<string, int> p1 = {"Aditya", 26}; // Declare and initialize Pair of string and int data type.
    cout << p1.first << endl;
    cout << p1.second << endl;
    cout << endl;

    pair<string , pair<char, int>> p2 = {"Amey", {'a',20}}; // Nested Pair
    cout << p2.first << endl;
    cout << p2.second.first << endl;
    cout << p2.second.second << endl;
    cout << endl;

    vector<pair<int, int>> v = {{1,2},{2,3},{4,5}}; // Vector of Pairs, We can also use auto keyword.
    v.push_back({6,7}); // Insert pair using initializer list.
    v.emplace_back(7,8); // In place object construction.
    v.push_back(make_pair(8,9)); // Insert pair using make_pair function.
    
    for(pair<int, int> p : v){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
}
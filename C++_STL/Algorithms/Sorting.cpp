#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second){
        return true; // Sort by second element
    }
    else{
        return false; // Do not swap
    } 
}

bool compare2(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second){
        return true; // Sort by first element
    }
    if(p1.second > p2.second){
        return false; // Do not swap
    }
    if(p1.first < p2.first){
        return true; // Sort by second element
    }
    else{
        return false; // Do not swap
    }
}

int main (){
    int arr[5] = {5,4,3,2,1}; // Array of 5 integers.
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n); // Sort in ascending order.
    cout << "Sort in ascending order (ARR) : ";
    for(int i : arr){
        cout << i << " ";
    }   
    cout << endl;

    sort(arr, arr+n, greater<int>()); // Sort in descending order.
    cout << "Sort in descending order (ARR) : ";
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;

    vector<int> v = {5,4,3,2,1}; // Vector of 5 integers.
    int m = v.size();
    sort(v.begin(), v.end()); // Sort in ascending order.
    cout << "Sort in ascending order (VECTOR) : ";
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>()); // Sort in descending order.
    cout << "Sort in descending order (VECTOR) : ";
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    vector<pair<int, int>> vp = {{1, 2}, {3, 1}, {2, 3}, {2, 1}}; // Vector of pairs.
    int p = vp.size();
    sort(vp.begin(), vp.end()); // Sort by first element, then by second element
    cout << "Sort by first element, then by second element (VECTOR of PAIRS) : ";
    for(auto i : vp){
        cout << "{" << i.first << ", " << i.second << "} ";
    }
    cout << endl;

    vector<pair<int, int>> vp2 = {{1, 2}, {3, 1}, {2, 3}, {2, 1}}; // Vector of pairs.
    int p2 = vp2.size();
    sort(vp2.begin(), vp2.end(), compare); // Sort by second element using custom comparator
    cout << "Sort by first element, then by second element (VECTOR of PAIRS) : ";
    for(auto i : vp2){
        cout << "{" << i.first << ", " << i.second << "} ";
    }
    cout << endl;

    vector<pair<int, int>> vp3 = {{1, 2}, {3, 1}, {2, 3}, {2, 1}}; // Vector of pairs.
    int p3 = vp3.size();
    sort(vp3.begin(), vp3.end(), compare2); // Sort by second element, then by first element using custom comparator
    cout << "Sort by second element, then by first element (VECTOR of PAIRS) : ";
    for(auto i : vp3){
        cout << "{" << i.first << ", " << i.second << "} ";
    }
    cout << endl;
}
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Using set approach O(n^2).
int finddup(vector<int> &arr){
    unordered_set<int> s;
    for(int i = 0; i < arr.size(); i++){
        int f = arr[i];
        if(s.find(f) != s.end()){
            return f;
        }
        s.insert(f);
    }
    return -1;
}

// Using Linked list O(1).
int finddupLL(vector<int> &arr){
    int s = arr[0];
    int f = arr[0];
    do{
        s = arr[s];
        f = arr[arr[f]];
    }while(s != f);
    s = arr[0];
    while(s != f){
        s = arr[s];
        f = arr[f];
    }
    return f;
}

int main (){
    vector<int> arr = {1,3,4,2,2};
    cout << "Duplicate using SET : " << finddup(arr) << endl;
    cout << "Duplicate using LINKED LIST : " << finddupLL(arr) << endl;
    return 0;
}
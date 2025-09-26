#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l = {1,2,3}; // Declare and initialize List.

    // Push an element in List.
    l.push_back(4); 
    l.emplace_back(5); 

    l.push_front(0); 
    l.push_front(-1);

    // Pop an element in List.
    l.pop_back();
    l.pop_front();

    cout << "List is : ";
    for(int i : l){
        cout << i << " ";
    }
    cout << endl;
}
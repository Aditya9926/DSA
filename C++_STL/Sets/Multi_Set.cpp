#include<iostream>
#include<set>
using namespace std;

int main (){
    multiset<int> ms;
    ms.insert(10);
    ms.insert(20);
    ms.insert(20);
    ms.insert(30);
    ms.insert(30); // allows duplicate values 
    ms.insert(30);
    ms.emplace(40);
    ms.emplace(50);

    cout<<"Size: "<<ms.size()<<endl;

    cout<<"Elements are: ";
    for (auto it: ms){ // sorted order
        cout<<it<<" ";
    }
    return 0;
}
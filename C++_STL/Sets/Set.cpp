#include<iostream>
#include<set>
using namespace std;

int main (){
    set<int> s;
    s.insert(5); // insertion in log(n) time.
    s.insert(2);
    s.insert(8);
    s.emplace(1);
    s.emplace(3);

    s.insert(5); //duplicates are not allowed
    s.insert(2);
    s.insert(8);
    s.emplace(1);
    s.emplace(3);

    cout << s.size() << endl; //5

    for(auto i:s){ // 1 2 3 5 8 sorted order
        cout<<i<<" ";
    }
    cout<<endl;

    cout << s.count(5) << endl; //1
    cout << s.count(10) << endl; //0

    s.erase(3); //log(n)
    for(auto i:s){ // 1 2 5 8
        cout<<i<<" ";
    }
    cout<<endl;

    s.find(5); //returns iterator to the element if found else returns s.end()
    auto it = s.find(2);
    if(it != s.end()){
        cout << *it << endl;
    }else{
        cout << "Not found" << endl;
    }

    cout << s.empty() << endl; //0

    cout << "Lower bound of 4: " << *s.lower_bound(4) << endl; //5
    cout << "Lower bound of 8: " << *s.lower_bound(8) << endl; //8

    cout << "Upper bound of 1: " << *s.upper_bound(1) << endl; //2
    cout << "Upper bound of 5: " << *s.upper_bound(5) << endl; //8

    return 0;   
}
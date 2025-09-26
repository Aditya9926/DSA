#include<iostream>
#include<unordered_set>
using namespace std;

int main (){
    unordered_set<int> s;
    s.insert(5); // O(1) average time complexity
    s.insert(5); // duplicate values are not allowed
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    for(auto i:s){ // no specific order
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Count of 5: "<<s.count(5)<<endl;
    cout<<"Count of 1: "<<s.count(1)<<endl;
    cout<<"Count of 3: "<<s.count(3)<<endl;

    auto it = s.find(5);
    if(it!=s.end()){
        cout<<"5 is present"<<endl;
    }else{
        cout<<"5 is not present"<<endl;
    }

    it = s.find(10);
    if(it!=s.end()){
        cout<<"10 is present"<<endl;
    }else{
        cout<<"10 is not present"<<endl;
    }

    cout << s.size();

    return 0;
}
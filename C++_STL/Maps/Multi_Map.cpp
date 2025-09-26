#include<iostream>
#include<map>
using namespace std;

int main(){
    multimap<string, int> m;
    m.insert({"Mango", 1});
    m.insert({"Apple", 2});
    m.insert({"Banana", 3});
    m.insert({"Mango", 4});

    m.emplace("Pineapple", 5);
    m.emplace("Apple", 6);
    m.emplace("Apple", 7);
    m.emplace("Banana", 8);
    m.emplace("Banana", 9);

    m.erase("Apple");
    m.erase(m.find("Banana"));

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}
#include<iostream>
#include<map>
using namespace std;

int main (){
    map<string, int> m;
    m["Mango"] = 100;
    m["Apple"] = 120;
    m["Banana"] = 20;
    m["Guava"] = 60;
    m["Orange"] = 80;

    m["Banana"] = 200; // Update the price of Banana.

    m.insert({{"Pineapple", 180}, {"Kiwi", 90}}); // Insert multiple values.
    m.emplace("Lichi", 70); // Insert using emplace.

    m.erase("Guava"); // Erase Guava from the map.

    cout << "MAP is : " << endl;
    for(auto i : m){
        cout << i.first << " : " << i.second;
        cout << endl;
    }
    cout << endl;

    cout << "Count of Banana is : " << m.count("Banana") << endl; // Count of Mango.

    cout << m["Mango"] << endl; // Accessing the price of Mango.

    if(m.find("Apple") != m.end()){
        cout << "Apple is present in the map." << endl;
    } else {
        cout << "Apple is not present in the map." << endl;
    }

    cout << "Size of the map is : " << m.size() << endl; // Size of the map.

    cout << "Is empty : " << m.empty() << endl; // Check if the map is empty.
}
#include<iostream>
using namespace std;

int main (){
    string str = "Aditya " ; // Dynamic in nature, resize at runtime.
    string str2 = "Sahu";

    cout << "Length of string is : " << str.length() << endl;

    string str3 = str + str2; // Concatenation
    string str4 = "Aditya ";

    cout << (str == str4) << endl; // Comparing Two strings.

    cout << (str < str2) << endl;

    cout << "Sum of string And string 2 is : " << str3 << endl;

    string str6;
    cout << "Enter a string : ";
    getline(cin, str6);
    cout << "Your string is : " <<str6 << endl;

    string str5;
    cout << "Enter a string : ";
    cin >> str5;
    cout << "Your string is : " << str5 << endl;

    for(int i = 0; i < str6.length();i++){
        cout << str6[i] << " ";
    } 
    cout << endl;

    for(auto ch : str6){
        cout << ch << " ";
    }
    cout << endl;
}
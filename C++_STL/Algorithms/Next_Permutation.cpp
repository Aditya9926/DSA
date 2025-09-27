#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main (){
    string str = "abc";
    cout << "Original string: " << str << endl;
    next_permutation(str.begin(), str.end()); // Generating the next permutation
    cout << "Next permutation: " << str << endl;

    string str2 = "cba";
    cout << "Original string: " << str2 << endl;
    prev_permutation(str2.begin(), str2.end()); // Generating the previous permutation
    cout << "Previous permutation: " << str2 << endl;
}
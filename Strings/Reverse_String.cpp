#include<iostream>
using namespace std;

int main (){
    string str;
    cout << "Your Enterd string is : " << str;
    getline(cin, str);

    for(int i = str.length(); i >= 0 ; i--){
        cout << str[i] << " ";
    }
    cout << endl;

    int s = 0, e = str.length()-1;
    while(s < e){
        swap(str[s],str[e]);
        s ++;
        e --;
    }
    for(auto i : str){
        cout << i << " ";
    }
    cout << endl;
}
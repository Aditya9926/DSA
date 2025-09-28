#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Static in nature. Non modifiable.
    char str1[] = "Hello";
    int arr[] = {1, 2, 3, 4, 5};

    cout << arr << endl;
    cout << str << endl;
    cout << str1 << endl;

    char str2[50];
    cout << "Enter your full name: ";
    cin.getline(str2, 50); // Reads the entire line including spaces
    cout << "Your full name is: " << str2 << endl;

    int len = 0;
    for(int i = 0; str2[i] != '\0'; i++){
        len++;
    }
    cout << "Length of your name is: " << len << endl;

    cout << "Length using strlen function: " << strlen(str2) << endl;

    for(auto i : str2){
        cout << i << " ";
    }
    cout << endl;
    
    cout << "Enter your full name: ";
    cin.getline(str2, 50,'h'); // Reads the entire line including spaces
    cout << "Your full name is: " << str2 << endl;

    getchar(); // To consume the newline character left in the buffer
    cout << "Enter your name: ";
    cin >> str2; // Only reads input until the first whitespace
    cout << "Your name is: " << str2 << endl;

    char str3[] = {"Aditya Sahu"};
    int s = 0, e = strlen(str3) - 1;
    while(s < e){
        swap(str3[s], str3[e]);
        s ++;
        e --;
    }
    for(char ch : str3){
        cout << ch << " ";
    }
    cout << endl;

    for(int i = strlen(str3); i >= 0; i--){
        cout << str3[i] << " ";
    }
    cout << endl;

    return 0;
}
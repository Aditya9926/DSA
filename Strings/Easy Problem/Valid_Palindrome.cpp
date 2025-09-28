#include<iostream>
using namespace std;

class Solution {
public:
    bool isvalid(char ch) {
        if (ch >= '0' && ch <= '9' ||
            tolower(ch) >= 'a' && tolower(ch) <= 'z') {
            return true;
        }
        return false;
    }

    bool isPalindrome(string str) {
        int s = 0, e = str.size() - 1;
        while (s < e) {
            if (!isvalid(str[s])) {
                s++;
                continue;
            }
            if (!isvalid(str[e])) {
                e--;
                continue;
            }
            if (tolower(str[s]) != tolower(str[e])) {
                return false;
            } else {
                s++;
                e--;
            }
        }
        return true;
    }
};

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    Solution obj;
    if (obj.isPalindrome(str)) {
        cout << "The string is a valid palindrome." << endl;
    } else {
        cout << "The string is not a valid palindrome." << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

string removeoccrence(string s, string part)
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string s, part;
    cout << "Enter the string : ";
    cin >> s ;
    cout << "Enter the part to be removed : ";
    cin >> part ;
    cout << removeoccrence(s, part) << endl;
    return 0;
}
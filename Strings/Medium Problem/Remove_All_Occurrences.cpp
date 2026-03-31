#include <iostream>
using namespace std;

// Optimized: Single pass approach to avoid redundant searching
// Time complexity: O(n) where n is length of string s
// Space complexity: O(n) for building the result string
string removeoccrence(string s, string part)
{
    int partLen = part.length();
    string result = "";

    for(int i = 0; i < s.length(); i++){
        result += s[i];

        // Check if the last partLen characters match the part to be removed
        if(result.length() >= partLen){
            bool match = true;
            for(int j = 0; j < partLen; j++){
                if(result[result.length() - partLen + j] != part[j]){
                    match = false;
                    break;
                }
            }
            if(match){
                // Remove the matched part
                result.erase(result.length() - partLen, partLen);
            }
        }
    }
    return result;
}

// Alternative: Using string builder approach for better performance
string removeoccrence_optimized(string s, string part)
{
    while (s.length() > 0 && s.find(part) != string::npos)
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
    cout << "Result (optimized): " << removeoccrence(s, part) << endl;
    return 0;
}
#include<iostream>
using namespace std;

class Solution {
public:

    bool isFreqSame(int f1[], int f2[]){
        for(int i = 0; i < 26; i++){
            if(f1[i] != f2[i]){
                return false;
            }
        }
        return true;
    }

    // Optimized: Proper sliding window with O(n) time complexity
    // Time complexity: O(n) instead of O(n*m*26)
    // Space complexity: O(1) - using fixed size arrays
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        if(len1 > len2) return false;

        // Build frequency map for s1
        int freq[26] = {0};
        for(int i = 0; i < len1; i++){
            freq[s1[i] - 'a']++;
        }

        // Build frequency map for first window in s2
        int windfreq[26] = {0};
        for(int i = 0; i < len1; i++){
            windfreq[s2[i] - 'a']++;
        }

        // Check first window
        if(isFreqSame(freq, windfreq)){
            return true;
        }

        // Slide the window across s2
        for(int i = len1; i < len2; i++){
            // Add new character to window
            windfreq[s2[i] - 'a']++;
            // Remove leftmost character from window
            windfreq[s2[i - len1] - 'a']--;

            if(isFreqSame(freq, windfreq)){
                return true;
            }
        }

        return false;
    }
};

int main (){
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution obj;
    if(obj.checkInclusion(s1,s2)){
        cout << "Yes, a permutation of the first string is present in the second string." << endl;
    } else {
        cout << "No, a permutation of the first string is not present in the second string." << endl;
    }
    return 0;
}
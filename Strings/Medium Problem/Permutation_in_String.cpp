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

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            freq[s1[i] - 'a'] ++;
        } 
        int windsize = s1.size();
        for(int j = 0; j < s2.size(); j++){
            int windidx = 0,windfreq[26] = {}, idx = j;
            while(windidx < windsize && idx < s2.size()){
                windfreq[s2[idx] - 'a'] ++;
                windidx ++;
                idx ++;
            }
            if(isFreqSame(freq,windfreq)){
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
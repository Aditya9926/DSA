#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

class Solution{
    public :

    // Better Approach :-
    int trap(vector<int>& height){
        int n = height.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            lmax[i] = max(lmax[i-1],height[i]);
        }

        for(int i = n-2; i >= 0; i--){
            rmax[i] = max(rmax[i+1],height[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(lmax[i], rmax[i]) - height[i];
        }
        return ans;
    }

    // Using Pointer :-
    int trappointer(vector<int>& height){
        int n = height.size();
        int ans = 0, l = 0, lmax = 0, rmax = 0;
        int r = n-1;

        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax,height[r]);

            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }
            else{
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Using Better Approach: ";
    cout << sol.trap(height) << endl;
    cout << "Using Two Pointer Approach: ";
    cout << sol.trappointer(height) << endl;
    return 0;
}
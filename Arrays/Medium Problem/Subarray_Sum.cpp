#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Brute Force Method.
int subarray(vector<int> &nums, int k){
    int n = nums.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

// Prefix Approach.
int subarraypr(vector<int> &nums, int k){
    // Case 1 :
    int n = nums.size();
    int count = 0;
    vector<int> ps(n,0);
    ps[0] = nums[0];
    for(int i = 1; i < n; i++){
        ps[i] = ps[i - 1] + nums[i];
    }

    // Case 2 :
    unordered_map<int,int> m;
    for(int j = 0; j < n; j++){
        if(ps[j] == k){
            count++;
        }
        int val = ps[j] - k;
        if(m.find(val) != m.end()){
            count += m[val];
        }
        
        if(m.find(ps[j]) == m.end()){
            m[ps[j]] = 0;
        }
        m[ps[j]]++;
    }
    return count;
}

int main(){
    vector<int> arr = {9,4,20,3,10,5};
    int tar = 33;
    cout << "Number of subarray using brute force method is : " << subarray(arr,tar);
    cout << "\nNumber of subarray using Prefix method method is : " << subarraypr(arr,tar);
}
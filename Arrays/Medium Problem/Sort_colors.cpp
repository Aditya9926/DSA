#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force Approach
void sortcolorbrute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

// optimized way 
void sortcoloroptimal(vector<int>& nums){
    int n = nums.size();
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] == 0){
            count0 ++;
        }
        else if(nums[i] == 1){
            count1 ++;
        }
        else{
            count2 ++;
        }
    }
    int index = 0;
    for(int i = 0; i < count0; i++){
        nums[index++] = 0;
    }
    for(int i = 0; i < count1; i++){
        nums[index++] = 1;
    }
    for(int i = 0; i < count2; i++){
        nums[index++] = 2;
    }
}

// Dutch national flag algorithm
void sortcolourDNF(vector<int>& nums){
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            mid ++;
            low ++;
        }
        else if(nums[mid] == 1){
            mid ++;
        }
        else{
            swap(nums[high],nums[mid]);
            high --;
        }
    }
}

int main(){
    vector<int> arr = {2,0,2,1,1,0};
    cout << "\nArray before sorting : ";
    for(int i : arr){
        cout << i << " ";
    }
    sortcolorbrute(arr);
    cout << "\nArray after sorting using brute force method : ";
    for (int i : arr){
        cout << i << " ";
    }
    sortcoloroptimal(arr);
    cout << "\nArray after sorting using Optimized way : ";
    for (int i : arr){
        cout << i << " ";
    }
    sortcolourDNF(arr);
    cout << "\nArray after sorting using Dutch national flag algorithm : ";
    for (int i : arr){
        cout << i << " ";
    }
}
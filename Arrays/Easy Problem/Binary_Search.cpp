#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int> arr, int tar){
    int str = 0, end = arr.size()-1; 
    while(str <= end){
        int mid = str + (str+end)/2; //we are not using (str+end)/2 because if the str and end is INT_MAX then there will be an overflow situation.
        if(tar > arr[mid]){
            str = mid+1;
        }
        else if(tar < arr[mid]){
            end = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    int target = 9;
    cout << binarysearch(arr1,target) << endl;
    vector<int> arr2 = {11,12,13,14,15,16,17,18,19};
    int target2 = 12;
    cout << binarysearch(arr2,target2) << endl;
}
#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int>& n, int tar,int start, int end){
    if(start <= end){
        int mid = start + (end - start) / 2;
        if(n[mid] == tar){
            return mid;
        }
        if(n[mid] <= tar){
            return binarysearch(n,tar,mid + 1,end);
        }
        if(n[mid] >= tar){
            return binarysearch(n,tar,start,end - 1);
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {-1,0,3,5,9,12};
    int tar = 9;
    int str = -1;
    int end = 12;
    cout << binarysearch(arr,tar,str,end);
}
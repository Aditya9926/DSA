#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Valid(vector<int> &arr, int n, int cows,int mid){
    int cow = 1, laststallposition = arr[0];
    for(int i =0; i < n; i++){
        if(arr[i] - laststallposition >= mid){
            cow ++;
            laststallposition = arr[i];
        }
        if(cow == cows ){
            return true;
        }
    }
    return false; 
}

int Aggressivecow(vector<int> &arr, int n, int cow){
    sort(arr.begin(),arr.end());
    int ans = -1;
    int str = 1,end = arr[n-1] - arr[0];
    while(str <= end){
        int mid = str +(end-str)/2;
        if(Valid(arr,n,cow,mid)){
            ans = mid;
            str = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,8,4,9};
    int n = 5,cow = 3;
    cout << Aggressivecow(arr,n,cow) << endl;
    return 0;
}
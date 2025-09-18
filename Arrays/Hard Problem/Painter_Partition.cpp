#include<iostream>
#include<vector>

using namespace std;

bool Valid(vector<int> &arr, int board, int painter,int mid){
    int person = 1, time = 0;
    for(int i =0; i < board; i++){
        if(arr[i] > mid){
            return false;
        }
        if(time + arr[i] <= mid){
            time += arr[i];
        }
        else{
            person ++;
            time = arr[i];
        }
    }
    return person > painter ? false : true ; 
}

int painterpartitin(vector<int> &arr, int board, int painter){
    int sum = 0;
    for(int i = 0; i < board; i++){
        sum += arr[i];
    }
    int ans = -1;
    int str = 0,end = sum;
    while(str <= end){
        int mid = str +(end-str)/2;
        if(Valid(arr,board,painter,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            str = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {40,30,10,20};
    int board = 4,painter = 2;
    cout << painterpartitin(arr,board,painter) << endl;
    return 0;
}
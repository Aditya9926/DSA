#include<iostream>
#include<vector>

using namespace std;

bool Valid(vector<int> &arr, int book, int person,int mid){
    int student = 1, pages = 0;
    for(int i =0; i < book; i++){
        if(arr[i] > mid){
            return false;
        }
        if(pages + arr[i] <= mid){
            pages += arr[i];
        }
        else{
            student ++;
            pages = arr[i];
        }
    }
    return student > person ? false : true ; 
}

int allocateBooks(vector<int> &arr, int book, int person){
    int sum = 0;
    for(int i = 0; i < book; i++){
        sum += arr[i];
    }
    int ans = -1;
    int str = 0,end = sum;
    while(str <= end){
        int mid = str +(end-str)/2;
        if(Valid(arr,book,person,mid)){
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
    vector<int> arr = {2,1,3,4};
    int book = 4,person = 2;
    cout << allocateBooks(arr,book,person) << endl;
    return 0;
}
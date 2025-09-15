#include<iostream>
#include<vector>
using namespace std;

class solution{
    public :
    int mountainarray(vector<int> &arr){
        int str = 0, end = arr.size()-2;
        while(str <= end){
            int mid = str + (end - str)/2;
            if(arr[mid -1] < arr[mid] && arr[mid] > arr[mid+1] ){
                return mid;
            }
            else if(arr[mid - 1] < arr[mid]){
                str = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {0,3,8,9,5,2};
    solution sol;
    int result = sol.mountainarray(arr);
    cout << result << endl;
}
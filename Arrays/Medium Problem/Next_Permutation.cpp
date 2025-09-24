#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int pivot = -1, n = nums.size();
    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i + 1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i = n-1; i > pivot; i--){
        if(nums[i] > pivot){
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    int i = pivot + 1, j = n - 1;
    while(i <= j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    } 
}

int main(){
    vector<int> arr = {1,1,5};
    nextPermutation(arr);
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}
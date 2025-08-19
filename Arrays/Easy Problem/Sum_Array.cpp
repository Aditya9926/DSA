#include <iostream>
using namespace std;

void sumArray(int arr[], int size){
    int sum = 0;
    for(int i = 0 ; i< size ;i++){
        sum += arr[i];
    }
    cout << "Sum of array elements is: " << sum << endl;
}

int main(){
    int size = 5;
    int arr[size];
    cout << "Enter " << size << " array elements: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    sumArray(arr, size);
    return 0;
}
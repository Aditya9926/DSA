#include <iostream>
using namespace std;

void min(int arr[]){
    int minu = arr[0];
    for(int i = 0; i < 5; i++){
        if (minu > arr[i]){
            minu = arr[i];
        }
    }
    cout<< "Minimum element is: " << minu <<"\n";
}

int main(){
    int arr1[5] = { 30, 10, 20, 40, 50 };    
    int arr2[5] = { 5, 15, 25, 35, 45};   
    min(arr1);    
    min(arr2); 
    return 0;
}
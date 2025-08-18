#include <iostream>
using namespace std;

void min(int arr[]){
    int minu = arr[0];
    for(int i = 0; i < 5; i++){
        if (minu > arr[i]){
            minu = arr[i];
            int index = i;
            cout << "Minimum element found at index: " << index << "\n";
        }
        
    }
    cout<< "Minimum element is: " << minu <<"\n";
}

int main(){
    int arr1[5] = { 30, 10, 20, 40, 50 };       
    min(arr1); 
    return 0;
}
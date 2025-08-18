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
    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    cout << "Array elements are: ";      
    min(arr); 
    return 0;
}
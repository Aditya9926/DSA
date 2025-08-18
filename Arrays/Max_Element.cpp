#include <iostream>
using namespace std;

void max(int arr[]){
    int maxi = arr[0];
    for(int i =0 ; i < 5 ; i++){
        if(maxi < arr[i]){
            maxi = arr[i];
        }
    }
    cout << "Maximum element is : " << maxi <<endl ;
}
int main(){
     int arr1[5] = { 25, 10, 54, 15, 40 };    
    int arr2[5] = { 12, 23, 44, 67, 54 };    
    max(arr1);  
    max(arr2);
    return 0;
}
#include <iostream>
using namespace std;

void max(int arr[]){
    int maxi = arr[0];
    int index = 0;
    for(int i =0 ; i < 5 ; i++){
        if(maxi < arr[i]){
            maxi = arr[i];
            index = i;
        }
    }
    cout << "Maximum element found at index: " << index << "\n";
    cout << "Maximum element is : " << maxi <<endl ;
}
int main(){
    int arr[5];
    cout << "Array elements are: ";
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    max(arr);
    return 0;
}
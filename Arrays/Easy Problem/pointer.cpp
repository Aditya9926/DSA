#include <iostream>
using namespace std;
 
void pointer(int *ptr){
    *ptr = 20;
}

void pointerin(int &b){
    b = 20;
}

int main(){
    // pass by reference
    int a = 10;
    pointer(&a);
    cout << "value of a using pass by reference : " << a << endl;

    // pass by reference by alias
    pointerin(a);
    cout <<"value of a using pass by reference alias : " << a << endl;

    // pointers in array
    int arr[] = {1,2,3,4,5};
    cout <<"It will return the first element in array : " << *arr <<endl;

    // pointer in array Add or Subtract 
    cout <<"It will return the next element in array : " << *(arr + 1) << endl;

    //ptr increment/decrement
    int l = 10;
    int *ptr = &l;
    cout <<"Pointer original address : " << ptr << endl;
    ptr = ptr+4;
    cout <<"Pointer updated address : " << ptr << endl; //increment by 4

    // Subtracting two pointer. We can't add two pointer  but we can compare two pointer using realtional operators.
    int *ptr1;
    int *ptr2;
    int *ptr3 = ptr1 + 2;
    cout << "Pointer 1 value is : " << ptr1 << endl;
    cout << "Pointer 2 value is : " << ptr2 << endl;
    cout << "Difference of pointer 1 and pointer 3 is : " << ptr3 - ptr1 << endl;
    cout << "Is pointer one is greater then pointer two " << (ptr1 < ptr2) << endl;
}
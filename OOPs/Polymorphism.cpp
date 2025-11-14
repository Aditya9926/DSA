#include<iostream>
using namespace std;

class student{
    public : 
    string name;

    // Constructor Overloading.
    student(){
        cout << "Non-Perameterized Constructor." << endl;
    }

    student(string name){
        this-> name = name;
        cout << "Perameterized Comstructor." << endl;
    }

    void getinfo(){
        cout << "Parent class." << endl;
    }

    virtual void hello(){
        cout << "Hello from Patent" << endl;
    }
};

class Print : public student{
    public : 

    // Function overloading.
    void show(int x){
        cout << "INT : " << x << endl;
    }

    void show(char x){
        cout << "CHAR : " << x << endl;
    }

    void getinfo(){
        cout << "Chile class." << endl;
    }
    void hello(){
        cout << "Hello from Child" << endl;
    }
};

int main(){
    student s1; // Non-Perameterized Constructor
    student s2("Aditya Sahu"); // Perameterized Constructor

    Print P1,P2;
    P1.show(101);
    P2.show('A');

    // Function overriding.
    P2.getinfo();
    P2.hello();
}
#include<iostream>
using namespace std;

class person{
public :

    string name;
    int age;

    person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class student : public person{  // Single Inheritance.
public: 

    int rollno;
    student(string name, int age, int rollno) : person(name,age){
        this->rollno = rollno;
    }

    void getinfo(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Rollno : " << rollno << endl;
    }
};

int main(){
    student s1("Aditya Sahu", 22, 500096455);
    s1.getinfo();
}
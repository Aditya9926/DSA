#include<iostream>
using namespace std;

class Person{
    public : 
    string name;
    int age;
};

class Student : public Person{
    public :
    int rollno;

    Student(string name, int age, int rollno){
        this-> name = name;
        this-> age = age;
        this-> rollno = rollno;
    }

    void Stuinfo(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Rollno : " << rollno << endl;
    }
};

class Teacher : public Person{
    public :
    string subject;

    Teacher(string name, int age, string subject){
        this-> name = name;
        this-> age = age;
        this-> subject = subject;
    }

    void Techinfo(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Subject : " << subject << endl;
    }
};

int main(){
    Student s1("Aditya Sahu", 22, 500096455);
    Teacher t1("Striver", 35, "Computer Science");
    s1.Stuinfo();
    t1.Techinfo();
}
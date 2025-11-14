#include<iostream>
using namespace std;

class student{
    public :
    string name;
    int rollno;
};

class teacher{
    public :
    string subject;
    double salary;
};

class TAs : public student, public teacher{
    public :
    void getinfo(){
        cout << "Name : " << name << endl;
        cout << "Rollno : " << rollno << endl;
        cout << "Salary : " << salary << endl;
        cout << "Subject : " << subject << endl;
    }
};

int main(){
    TAs t1;
    t1.name = "Aditya Sahu";
    t1.rollno = 500096455;
    t1.salary = 200000;
    t1.subject = "Computer Science";
    t1.getinfo();
}
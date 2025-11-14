#include<iostream>
using namespace std;

class person{
    public :
        string name;
        int age;
};

class student : public person{
    public : 
        int rollno;
};

class GradStudent : public student{
    public : 
        string research;

    void getinfo(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Rollno : " << rollno << endl;
        cout << "Research : " << research << endl;
    }
};

int main(){
    GradStudent g1;
    g1.name = "Aditya Sahu";
    g1.age = 22;
    g1.rollno = 500096455;
    g1.research = "Big Data";
    g1.getinfo();
    return 0;
}
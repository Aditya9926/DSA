#include<iostream>
using namespace std;

class student{
    private :
        string Enrolement_Number;
    public : 
        string name;
        int rollno;
        int age;
        double* CGPAptr;
    
    student(string name, int rollno, string Enrolement_Number, int age,double CGPA){
        this-> name = name;
        this-> rollno = rollno;
        this-> Enrolement_Number = Enrolement_Number;
        this-> age = age;
        CGPAptr = new double;
        *CGPAptr = CGPA;
    }

    void getinfo(){
        cout << "Name : " << name << endl;
        cout << "Roll No : " << rollno << endl;
        cout << "Enrolement Number : " << Enrolement_Number << endl;
        cout << "Age : " << age << endl;
        cout << "CGPA : " << *CGPAptr << endl;
    }

    // Destructor : Create automatically after the main function if not made.
    ~student(){
        cout << "Hi I delete everything." << endl;
        delete CGPAptr;
    }
};

int main(){
    student s1("Aditya Sahu",500096455,"R252221087", 22, 8.9);
    s1.getinfo();
}
#include<iostream>
using namespace std;

class students{
    private :
        string Enrolement_number;
    public :
        string name;
        int rollno;
        int age;
        double* CGPAPtr;

        // Constructor.
        students(string name, int rollno,string Enrolement_number, int age,double CGPA){
            this-> name = name;
            this-> rollno = rollno;
            this-> Enrolement_number = Enrolement_number;
            this-> age = age;
            CGPAPtr = new double;
            *CGPAPtr = CGPA;
        }

        void getinfo(){
            cout << "Name : " << name << endl;
            cout << "Roll No : " << rollno << endl;
            cout << "Enrolement Number : " << Enrolement_number << endl;
            cout << "Age : " << age << endl;
            cout << "CGPA : " << *CGPAPtr << endl;
        }

        students(students &orgobj){
            cout << "This is my own copy constructor." << endl;
            this-> name = orgobj.name;
            this-> rollno = orgobj.rollno;
            this-> Enrolement_number = orgobj.Enrolement_number;
            this-> age = orgobj.age;
            CGPAPtr = new double;
            *CGPAPtr = *orgobj.CGPAPtr;
        }

        void setEnroll(string s){
            Enrolement_number = s;
        }

        void getEnroll(){
            cout << Enrolement_number << endl;
        }
};

int main(){
    students s1("Aditya Sahu", 500096455 ,"R252221087", 22, 8.90);
    students s2(s1); // Default copy constructor.
    s2.name = "Amey Sahu";
    s2.rollno = 500096444;
    s2.setEnroll("R252221086");
    s2.age = 20;
    *(s2.CGPAPtr) = 9;

    s1.getinfo(); // Shallow Copy : we changed the CGPA of s2 but it will refelect in s1 CGPA too.
    s2.getinfo();
}
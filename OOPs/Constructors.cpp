#include<iostream>
using namespace std;

class Teachers{
    private :
        double salary;

    public : 
        // Constructors.

        // Non-Perameterized Constructors.
        Teachers(){
            department = "Computer Science";
        }

        // Parameterized Constructor.
        Teachers(string name, string subject, string department, double salary){
            this->name = name;
            this->subject = subject;
            this->department = department;
            this->salary = salary;
        }

        // Copy constructors.
        Teachers(Teachers &orgobj){ // Pass by reference.
            cout << "I am custom copy costructor." << endl;
            this->name = orgobj.name;
            this->subject = orgobj.subject;
            this->department = orgobj.department;
            this->salary = orgobj.salary;
        }

        string name;
        string department;
        string subject; 

        void getinfo(){
            cout << "Name : " << name << endl;
            cout << "Subject : " << subject << endl;
            cout << "Department : " << department << endl;
            cout << "Salary : " << salary << endl;
        }
};

int main(){
    Teachers t1("Aditya","C++","Computer Science",200000);
    // t1.getinfo();
    Teachers t2(t1); // Default copy constructor if don't add the copy constructor.
    t2.getinfo(); 
}
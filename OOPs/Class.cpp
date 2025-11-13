#include <iostream>
using namespace std;

class teachers
{
private :
    double salary;
public:

    // Constructor
    teachers(){
        department = "Computer Science.";
    }

    // Properties OR Attributes
    string name;
    string department;
    string subject;

    // Methods OR Member Function
    void changedepartment(string newdepartme)
    {
        department = newdepartme;
    }

    // Setter
    void setsalary(double s){
        salary = s;
    }

    // Getter
    double getsalary(){
        return salary;
    }
};

class BankAccount{
    private :
        // Data Hiding
        int password;
        double balance;
    
    public :
        string username;
        int AccountID;
};

int main()
{
    teachers T1; // Constructor call
    T1.name = "Aditya";
    T1.subject = "C++";
    T1.setsalary(200000);
    cout << T1.getsalary() << endl;
    cout << T1.department << endl;
}
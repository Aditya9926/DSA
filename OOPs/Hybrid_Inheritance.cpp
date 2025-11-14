#include<iostream>
using namespace std;

class Person{
    public : 
    string name;
    int age;
};

class Student : virtual public Person{
    public :
    int rollno;

    Student(){

    }

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

class Teacher : virtual public Person{
    public :
    string subject;

    Teacher(){

    }

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

class Gradstudent : public Student{
    public :
    string stream;

    Gradstudent(string name, int age, int rollno, string stream){
        this-> name = name;
        this-> age = age;
        this-> rollno = rollno;
        this-> stream = stream;
    }

    void Gradstuinfo(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Rollno : " << rollno << endl;
        cout << "Stream : " << stream << endl;
    }
};

class TAs : public Student, public Teacher{
    public :
    double salary;

    TAs(string name, int age, int rollno,string subject, double salary){
        this-> name = name;
        this-> age = age;
        this-> rollno = rollno;
        this-> subject = subject;
        this-> salary = salary;
    }

    void Tainfo(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Rollno : " << rollno << endl;
        cout << "Stream : " << subject << endl;
        cout << "Salary : " << salary << endl;
    }
};

int main(){
    Student s1("Aditya Sahu", 22, 500096455);
    Teacher t1("Striver", 35, "Computer Science");
    Gradstudent gs1("Amey Sahu", 22, 500096444, "Computer Science");
    TAs ta1("Anmol", 28, 500096433,"Computer Science",20000);
    s1.Stuinfo();
    t1.Techinfo();
    gs1.Gradstuinfo();
    ta1.Tainfo();
}
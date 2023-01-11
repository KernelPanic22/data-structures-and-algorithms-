#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age);
    void print();
    ~Person();
    Person(const Person &p);
    Person &operator=(const Person &p);
    string getName() { return name; }
    int getAge() { return age; }

private:
    string name;
    int age;
};

Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

void Person::print()
{
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
}

Person::~Person()
{
}

Person::Person(const Person &p)
{
    this->name = p.name;
    this->age = p.age;
}

Person &Person::operator=(const Person &p)
{
    this->name = p.name;
    this->age = p.age;
    return *this;
}

// we define that student inherits from person
class Student : public Person
{
public:
    Student(string name, int age, string major);
    string getMajor() { return major; }
    int getGraduationYear() { return graduationYear; }
    void print();
    ~Student();
    Student(const Student &s);
    Student &operator=(const Student &s);
    void changeMajor(const string& newMajor);
private:
    string major;
    int graduationYear;
};

Student::Student(string name, int age, string major) : Person(name, age)
{
    this->major = major;
    this->graduationYear = 2019;
}

void Student::print()
{
    Person::print();
    cout << "Major: " << this->major << endl;
    cout << "Graduation Year: " << this->graduationYear << endl;
}

Student::~Student()
{
}

Student::Student(const Student& s) : Person(s)
{
    this->major = s.major;
    this->graduationYear = s.graduationYear;
}

Student &Student::operator=(const Student& s)
{
    Person::operator=(s);
    this->major = s.major;
    this->graduationYear = s.graduationYear;
    return *this;
}

void Student::changeMajor(const string& newMajor)
{
    this->major = newMajor;
}

int main()
{
    Student s("John", 20, "Computer Science");
    s.print();
    s.changeMajor("Math");
    s.print();
    return 0;
}
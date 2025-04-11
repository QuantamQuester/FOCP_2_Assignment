#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    float cgpa;
    string courses[10];
    int courseCount;

    Student() {
        name = "";
        rollNumber = 0;
        cgpa = 0.0;
        courseCount = 0;
    }

    Student(string n, int roll, float c) {
        name = n;
        rollNumber = roll;
        cgpa = (c >= 0.0 && c <= 10.0) ? c : 0.0;
        courseCount = 0;
    }

    void addCourse(string course) {
        for (int i = 0; i < courseCount; ++i) {
            if (courses[i] == course) return;
        }
        if (courseCount < 10) courses[courseCount++] = course;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Courses: ";
        for (int i = 0; i < courseCount; ++i) cout << courses[i] << " ";
        cout << endl;
    }
};

class StudentManagementSystem {
public:
    Student students[100];
    int studentCount;

    StudentManagementSystem() {
        studentCount = 0;
    }

    void addStudent(Student s) {
        if (studentCount < 100) students[studentCount++] = s;
    }

    Student* searchStudent(int roll) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].rollNumber == roll) return &students[i];
        }
        return nullptr;
    }

    void displayAll() {
        for (int i = 0; i < studentCount; ++i) {
            students[i].displayInfo();
            cout << "-------------------------\n";
        }
    }
};

int main() {
    StudentManagementSystem sms;

    Student s1("Alice", 101, 8.5);
    s1.addCourse("Math");
    s1.addCourse("Physics");

    Student s2("Bob", 102, 7.8);
    s2.addCourse("Chemistry");

    sms.addStudent(s1);
    sms.addStudent(s2);

    sms.displayAll();

    int roll = 101;
    Student* found = sms.searchStudent(roll);
    if (found) {
        cout << "\nDetails of student with roll number " << roll << ":\n";
        found->displayInfo();
    } else {
        cout << "\nStudent not found.\n";
    }

    return 0;
}
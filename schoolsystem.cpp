//This project involves designing functions for student enrollment, attendance tracking, and grade management
//The program should be able to add students and teachers to the school, display all students and teachers, and exit the programq

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a student
struct Student {
    string name;
    int age;
    string grade;
    string address;
};


struct Teacher {
    string name;
    string subject;
};


struct School {
    string name;
    vector<Student> students;
    vector<Teacher> teachers;
};

// Function to add a new student to the school
void addStudent(School& school) {
    Student newStudent;
    cout << "Enter student name: ";
    cin.ignore(); // Ignore the newline character left by cin
    getline(cin, newStudent.name);
    cout << "Enter student age: ";
    cin >> newStudent.age;
    cout << "Enter student grade: ";
    cin.ignore(); 
    getline(cin, newStudent.grade);
    cout << "Enter student address: ";
    getline(cin, newStudent.address);

    school.students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

// Function to add a new teacher to the school
void addTeacher(School& school) {
    Teacher newTeacher;
    cout << "Enter teacher name: ";
    cin.ignore(); 
    getline(cin, newTeacher.name);
    cout << "Enter teacher subject: ";
    getline(cin, newTeacher.subject);

    school.teachers.push_back(newTeacher);
    cout << "Teacher added successfully!" << endl;
}

// Function to display all students in the school
void displayStudents(const School& school) {
    cout << "\nStudents:" << endl;
    cout << "-----------------------------------" << endl;
    for (const auto& student : school.students) {
        cout << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << ", Address: " << student.address << endl;
    }
    cout << "-----------------------------------" << endl;
}


void displayTeachers(const School& school) {
    cout << "\nTeachers:" << endl;
    cout << "-----------------------------------" << endl;
    for (const auto& teacher : school.teachers) {
        cout << "Name: " << teacher.name << ", Subject: " << teacher.subject << endl;
    }
    cout << "-----------------------------------" << endl;
}

int main() {
    School school;
    school.name = "XYZ School";

    int choice;

    do {
        cout << "\nSchool Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Display Students\n";
        cout << "4. Display Teachers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(school);
                break;
            case 2:
                addTeacher(school);
                break;
            case 3:
                displayStudents(school);
                break;
            case 4:
                displayTeachers(school);
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
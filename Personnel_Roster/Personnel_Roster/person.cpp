//  Person.cpp
//
//  Personnel_Roster
//
//  Created by Lauren Vazquez on 9/10/22.
//
//  Create a Person class with variables, mutators, accessors, constructors, and print function
#include "person.hpp"
#include <string>

using namespace std;

// Default Constructor
Person::Person() {}

// Second Constructor
Person::Person(Grade personGrade, string personLastName, string personFirstName, string personMiddleName, Gender personGender, JobCode personJobCode, int personBirthday, int personBASD, int personDOR) {
    grade = personGrade;
    lName = personLastName;
    fName = personFirstName;
    mName = personMiddleName;
    gender = personGender;
    code = personJobCode;
    birthday = personBirthday;
    basd = personBASD;
    dor = personDOR;
}

// Setters
void Person::SetGrade(Grade personGrade) {
    grade = personGrade;
}
void Person::SetLastName(string personLastName) {
    lName = personLastName;
}
void Person::SetFirstName(string personFirstName) {
    fName = personFirstName;
}
void Person::SetMiddleName(string personMiddleName) {
    mName = personMiddleName;
}
void Person::SetGender(Gender personGender) {
    gender = personGender;
}
void Person::SetJobCode(JobCode personJobCode) {
    code = personJobCode;
}
void Person::SetBirthday(int personBirthday) {
    birthday = personBirthday;
}
void Person::SetBASD(int personBASD) {
    basd = personBASD;
}
void Person::SetDOR(int personDOR) {
    dor = personDOR;
}

// Getters
Grade Person::GetGrade() const {
    return grade;
}
string Person::GetLastName() const {
    return lName;
}
string Person::GetFirstName() const {
    return fName;
}
string Person::GetMiddleName() const {
    return mName;
}
Gender Person::GetGender() const {
    return gender;
}
JobCode Person::GetJobCode() const {
    return code;
}
int Person::GetBirthday() const {
    return birthday;
}
int Person::GetBASD() const {
    return basd;
}
int Person::GetDOR() const {
    return dor;
}

// Print function
void Person::PrintPerson() {
    cout << "Grade: " << GradeStrings[(int)GetGrade()] << endl;
    cout << "Last Name: " << GetLastName() << endl;
    cout << "First Name: " << GetFirstName() << endl;
    cout << "Middle Name: " << GetMiddleName() << endl;
    cout << "Gender: " << GenderStrings[(int)GetGender()] << endl;
    cout << "Job Code: " << JobCodeStrings[(int)GetJobCode()] << endl;
    cout << "Birthday: " << GetBirthday() << endl;
    cout << "Basic Active Service Date: " << GetBASD() << endl;
    cout << "Date of Rank: " << GetDOR() << endl;
    cout << "\n" << endl;
}

// Destructor
Person::~Person() {}

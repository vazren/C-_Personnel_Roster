//  person.hpp
//
//  Personnel_Roster
//
//  Created by Lauren Vazquez on 9/10/22.
//
//  Create a person class with data variables, mutators, accessors, constructors, and print function
#pragma once

#include "job_code.hpp"
#include "grade.hpp"
#include "gender.hpp"
#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
    
    // Default Constructor
        Person();
    
    // Second Constructor
        Person(Grade personGrade, string personLastName, string personFirstName, string personMiddleName, Gender personGender, JobCode personJobCode, int personBirthday, int personBASD, int personDOR);
    
    // Destructor
        ~Person();
    
    // Setters (Mutators)
        void SetGrade(Grade personGrade);
        void SetLastName(string personLastName);
        void SetFirstName(string personFirstName);
        void SetMiddleName(string personMiddleName);
        void SetGender(Gender personGender);
        void SetJobCode(JobCode personJobCode);
        void SetBirthday(int personBirthday);
        void SetBASD(int personBASD);
        void SetDOR(int personDOR);
    
    // Getters (Accessors)
        Grade GetGrade() const;
        string GetLastName() const;
        string GetFirstName() const;
        string GetMiddleName() const;
        Gender GetGender() const;
        JobCode GetJobCode() const;
        int GetBirthday() const;
        int GetBASD() const;
        int GetDOR() const;
    
    // Print Function
        void PrintPerson();
    
// person Variables
    private:
        Grade grade;
        string lName;
        string fName;
        string mName;
        Gender gender;
        JobCode code;
        int birthday;
        int basd;
        int dor;
};

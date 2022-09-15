//  roster.hpp
//
//  Personnel_Roster
//
//  Created by Lauren Vazquez on 9/10/22.
//
// Create a roster class with array of pointers and several functions to add, modify and display data
#pragma once

#include "person.hpp"
#include <iostream>

using namespace std;

class Roster {
    public:
    
    // Constructor
        Roster();
    
    // Destructor
        ~Roster();
    
        int index = -1;
        static const int numPersons = 5;
    
    // Array of pointers
    Person* rosterArray[numPersons];
    
    // Add function to update roster
        void Add(Grade grade, string lName, string fName, string mName, Gender gender, JobCode code, int birthday, int basd, int dor);
    
    // Parse and add function to parse data set in personnel data table and add to roster using above funtion
        void ParseAndAdd(string personData);
    
    // Remove function to remove records based on last and first name with confirmation prompt and messages
        void Remove(string lName, string fName);
    
    // Print function that loops through and prints all personnel
        void PrintAll();
    
    // Print function that prints personnel by grade
        void PrintByGrade(Grade grade);
    
     // Print function that prints personnel by job code
        void PrintByJobCode(JobCode code);   

    private:
        string personData;
        int i;
};

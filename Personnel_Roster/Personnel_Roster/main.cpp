//  main.cpp
//
//  Personnel_Roster
//
//  Created by Lauren Vazquez on 9/10/22.
//
#include "roster.hpp"
#include <iostream>

using namespace std;

int main() {
    
// Person data table modified with data
    string personData[] =
    {
        "E-7,Vazquez,Lauren,Olivia,Female,14E,19910306,20100630,20190701",
        "E-4,Smith,John,Allen,Male,14H,19930621,20170301,20190301",
        "O-1,Guy,Joseph,Robert,Male,14A,19970112,20200801,20200801",
        "E-5,Pratt,Brian,Travis,Male,25H,19950228,20171001,20210401",
        "WO1,Frick,Samantha,Lee,Female,140K,19941114,20120919,20211201",
    };
    
    int numStudents = 5;
    int i;
    
// Print description
    cout << "Personnel Database" << endl;
    
// Instantiate roster class as personRoster
    Roster personRoster;
    
// Parse and add each person to personRoster
    for (i = 0; i < numStudents; i++) {
        personRoster.ParseAndAdd(personData[i]);
    }

// Print all records
    personRoster.PrintAll();

// Print each person in the specified grade
    personRoster.PrintByGrade(Grade::E4);
    
// Print each person in the specified job code
    personRoster.PrintByJobCode(JobCode::H25);

// Remove the record for specified last and first name. Print success message and error if not found
    personRoster.Remove("Vazquez", "Lauren");
    
// Print all people to verify removal of person specified above
    personRoster.PrintAll();
    
// Verify that error message displays due previous removal of person
    personRoster.Remove("Vazquez", "Lauren");
    
// Implement destructor
    personRoster.~Roster();
    
    return 0;
}

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
    
// Instantiate roster class as personRoster
    Roster personRoster;
    
// Parse and add each person to personRoster
    for (i = 0; i < numStudents; i++) {
        personRoster.ParseAndAdd(personData[i]);
    }
    while (true) {
        
        int input;
        
        cout << "Personnel Database\n" << endl;
        cout << "Select one of the options below." << endl;
        cout << "\t1. Display all personnel records" << endl;
        cout << "\t2. Search for records based on name" << endl;
        cout << "\t3. Display records in the specified grade" << endl;
        cout << "\t4. Display records in the specified job" << endl;
        cout << "\t5. Delete record" << endl;
        cout << "\t6. Quit\n" << endl;
        cout << "Enter your selection: ";
        cin >> input;
        cout << "\n";
        
        switch(input) {
            case 1:
                personRoster.PrintAll();
                personRoster.ReturnToMenu();
                break;
            case 2:
                personRoster.PrintByName();
                personRoster.ReturnToMenu();
                break;
            case 3:
                personRoster.PrintByGrade();
                personRoster.ReturnToMenu();
                break;
            case 4:
                personRoster.PrintByJobCode();
                personRoster.ReturnToMenu();
                break;
            case 5:
                personRoster.Remove();
                personRoster.ReturnToMenu();
                break;
            case 6:
                exit(0);
                break;
                
        }
    }

/*// Print all records
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
*/
    return 0;
}

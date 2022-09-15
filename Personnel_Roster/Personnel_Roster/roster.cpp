//  roster.cpp
//
//  Personnel_Roster
//
//  Created by Lauren Vazquez on 9/10/22.
//
// Create a roster class with several functions to add, modify and display data
#include "roster.hpp"
#include <string>

using namespace std;

// Roster Constructor
Roster::Roster() {};

// Add function to update roster
void Roster::Add(Grade grade, string lName, string fName, string mName, Gender gender, JobCode code, int birthday, int basd, int dor) {
        rosterArray[++index] = new Person(grade, lName, fName, mName, gender, code, birthday, basd, dor);
}

// Parse and add function to parse data set in Person data table and add to roster using above funtion
void Roster::ParseAndAdd(string personData) {
    size_t rhs = personData.find(",");
    string strGrade = personData.substr(0, rhs);
    
    Grade grade = Grade::E1;
    if (strGrade == "E-1") {
        grade = Grade::E1;
    }
    else if (strGrade == "E-2") {
        grade = Grade::E2;
    }
    else if (strGrade == "E-3") {
        grade = Grade::E3;
    }
    else if (strGrade == "E-4") {
        grade = Grade::E4;
    }
    else if (strGrade == "E-5") {
        grade = Grade::E5;
    }    
    else if (strGrade == "E-6") {
        grade = Grade::E6;
    }
    else if (strGrade == "E-7") {
        grade = Grade::E7;
    }
    else if (strGrade == "WO1") {
        grade = Grade::WO1;
    }
    else if (strGrade == "CW2") {
        grade = Grade::CW2;
    }    
    else if (strGrade == "CW3") {
        grade = Grade::CW3;
    }
    else if (strGrade == "O-1") {
        grade = Grade::O1;
    }
    else if (strGrade == "O-2") {
        grade = Grade::O2;
    }
    else if (strGrade == "O-3") {
        grade = Grade::O3;
    }  

    size_t lhs = rhs + 1;
    rhs = personData.find(",", lhs);
    string lName = personData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = personData.find(",", lhs);
    string fName = personData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = personData.find(",", lhs);
    string mName = personData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = personData.find(",", lhs);
    string strGender = personData.substr(lhs, rhs - lhs);

    Gender gender = Gender::Male;
    if (strGender == "Male") {
        gender = Gender::Male;
    }
    else if (strGender == "Female") {
        gender = Gender::Female;
    }

    lhs = rhs + 1;
    rhs = personData.find(",", lhs);
    string strCode = personData.substr(lhs, rhs - lhs);

    JobCode code = JobCode::A14;
    if (strCode == "14A") {
        code = JobCode::A14;
    }
    else if (strCode == "14E") {
        code = JobCode::E14;
    }
    else if (strCode == "14H") {
        code = JobCode::H14;
    }
    else if (strCode == "25H") {
        code = JobCode::H25;
    }
    else if (strCode == "140K") {
        code = JobCode::K140;
    }
    else if (strCode == "14T") {
        code = JobCode::T14;
    }
    else if (strCode == "14Z") {
        code = JobCode::Z14;
    }
    else if (strCode == "Other") {
        code = JobCode::Other;
    }
    
    lhs = rhs + 1;
    rhs = personData.find(",", lhs);
    int birthday = stoi(personData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = personData.find(",", lhs);
    int basd = stoi(personData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = personData.find(",", lhs);
    int dor = stoi(personData.substr(lhs, rhs - lhs));
    
    Add(grade, lName, fName, mName, gender, code, birthday, basd, dor);
}

// Remove function to remove records based on last and first name with confirmation prompt and messages
void Roster::Remove(string lName, string fName) {
    string usrinput;
    bool nameExists = false;
    cout << "Confirm removal of " << lName << ", " << fName << " Y/N: ";
    cin >> usrinput;
    if (usrinput == "Y" || usrinput == "y") {
        for (i = 0; i < index + 1; i++) {
            if (rosterArray[i] != NULL) {
                if (rosterArray[i]->GetLastName() == lName && rosterArray[i]->GetFirstName() == fName) {
                    rosterArray[i] = nullptr;
                    nameExists = true;
                }
            }
        }
    }
    else if (usrinput == "N" || usrinput == "n") {
        cout << "\nAction cancelled\n\n" << endl;
        cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
        return;
    }
    else {
        cout << "\nInvalid input. Please try again\n\n" << endl;
        cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
        return;
    }
    if (nameExists) {
        cout << "\nPerson has been removed. \n\n" << endl;
        cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
    }
    else if (!nameExists){
        cout << "\nPerson does not exist. \n\n" << endl;
        cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
    }
}

// Print function that loops through and prints all person records
void Roster::PrintAll() {
    cout << "Person records:\n" << endl;
    for (i = 0; i < index + 1; i++) {
        if (rosterArray[i] != nullptr) {
            rosterArray[i]->PrintPerson();
        }
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
}

// Print function that prints Person records for the specified grade
void Roster::PrintByGrade(Grade grade) {
    cout << "The following records exist for the selected grade:\n" << endl;
    for (i = 0; i < index + 1; i++) {
        if (rosterArray[i]->GetGrade() == grade) {
            rosterArray[i]->PrintPerson();
        }
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
}

// Print function that prints Person records for the specified job code
void Roster::PrintByJobCode(JobCode code) {
    cout << "The following records exist for the selected job code:\n" << endl;
    for (i = 0; i < index + 1; i++) {
        if (rosterArray[i]->GetJobCode() == code) {
            rosterArray[i]->PrintPerson();
        }
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
}

// Destructor
    Roster::~Roster() {
        for (i = 0; i < numPersons; ++i) {
                delete rosterArray[i];
                rosterArray[i] = nullptr;
        }
}

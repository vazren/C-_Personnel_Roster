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
    cout << "\n";
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

// Prompts user to input last and first name to be removed using the above function
void Roster::Remove() {
    string lName;
    string fName;
    cout << "Enter the last name of the record to be removed: ";
    cin >> lName;
    cout << "\nEnter the first name of the record to be removed: ";
    cin >> fName;
    cout << "\n";
    
    Remove(lName, fName);
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

// Print function that prints the name inputted by the user
void Roster::PrintByName(string lName, string fName) {
    bool nameExists = false;
    for (i = 0; i < index + 1; i++) {
        if (rosterArray[i] != NULL) {
            if (rosterArray[i]->GetLastName() == lName && rosterArray[i]->GetFirstName() == fName) {
                rosterArray[i]->PrintPerson();
                nameExists = true;
            }
        }
    }
    if (!nameExists) {
        cout << "\nRecord does not exist for that name\n\n" << endl;
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
}

// Gets user input and prints name using the above function
void Roster::PrintByName() {
    string lName;
    string fName;
    cout << "Enter the last name of the record to display: ";
    cin >> lName;
    cout << "\nEnter the first name of the record to display: ";
    cin >> fName;
    cout << "\n";
    
    PrintByName(lName, fName);
}

// Print function that prints Person records for the specified grade
void Roster::PrintByGrade(Grade grade) {
    bool gradeExists = false;
    for (i = 0; i < index + 1; i++) {
        if (rosterArray[i]->GetGrade() == grade) {
            cout << "The following records exist for the selected grade:\n" << endl;
            rosterArray[i]->PrintPerson();
            gradeExists = true;
        }
    }
    if (!gradeExists){
        cout << "No records exist\n" << endl;
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
}

// Gets input and prints using the above function
void Roster::PrintByGrade() {
    string input;
    cout << "The following grades are valid:\nE-1\tE-2\tE-3\tE-4\tE-5\tE-6\tE-7\tWO1\tCW2\tCW3\tO-1\tO-2\tO-3\n\n";
    cout << "Enter grade to be displayed (ie. E-5, CW2, O-1): ";
    cin >> input;
    cout << "\n" << endl;
    if (input.rfind("E", 0) == 0 || input.rfind("e", 0) == 0) {
        if (input.rfind("1", 2) == 2) {
            PrintByGrade(Grade::E1);
        }
        else if (input.rfind("2", 2) == 2) {
            PrintByGrade(Grade::E2);
        }
        else if (input.rfind("3", 2) == 2) {
            PrintByGrade(Grade::E3);
        }
        else if (input.rfind("4", 2) == 2) {
            PrintByGrade(Grade::E4);
        }
        else if (input.rfind("5", 2) == 2) {
            PrintByGrade(Grade::E5);
        }
        else if (input.rfind("6", 2) == 2) {
            PrintByGrade(Grade::E6);
        }
        else if (input.rfind("7", 2) == 2) {
            PrintByGrade(Grade::E7);
        }
        else {
            cout << "Invalid Grade\n\n" << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
        }
    }
    else if (input.rfind("W", 0) == 0 || input.rfind("w", 0) == 0) {
        if (input.rfind("1", 2) == 2) {
            PrintByGrade(Grade::WO1);
        }
        else {
            cout << "Invalid Grade\n\n" << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
        }
    }
    else if (input.rfind("C", 0) == 0 || input.rfind("c", 0) == 0) {
        if (input.rfind("2", 2) == 2) {
            PrintByGrade(Grade::CW2);
        }
        else if (input.rfind("3", 2) == 2) {
            PrintByGrade(Grade::CW3);
        }
        else {
            cout << "Invalid Grade\n\n" << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
        }
    }
    else if (input.rfind("O", 0) == 0 || input.rfind("o", 0) == 0) {
        if (input.rfind("1", 2) == 2) {
            PrintByGrade(Grade::O1);
        }
        else if (input.rfind("2", 2) == 2) {
            PrintByGrade(Grade::O2);
        }
        else if (input.rfind("3", 2) == 2) {
            PrintByGrade(Grade::O3);
        }
        else {
            cout << "Invalid Grade\n\n" << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
        }
    }
    else {
        cout << "Invalid Grade\n\n" << endl;
        cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
    }
}

// Print function that prints Person records for the specified job code
void Roster::PrintByJobCode(JobCode code) {
    bool jobCodeExists = false;
    for (i = 0; i < index + 1; i++) {
        if (rosterArray[i]->GetJobCode() == code) {
            cout << "The following records exist for the selected job code:" << endl;
            rosterArray[i]->PrintPerson();
            jobCodeExists = true;
        }
    }
    if (!jobCodeExists) {
        cout << "No records exist\n\n" << endl;
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
}

// Gets user input and prints using the above function
void Roster::PrintByJobCode() {
    string input;
    cout << "The following job codes are valid:\n14E\t14H\t14T\t14Z\t25H\t14A\t140K\n\n";
    cout << "Enter job code to be displayed: ";
    cin >> input;
    cout << "\n" << endl;
    if (input.rfind("1", 0) == 0 && input.rfind("4", 1) == 1) {
        if (input.rfind("A", 2) == 2) {
            PrintByJobCode(JobCode::A14);
        }
        else if (input.rfind("E", 2) == 2) {
            PrintByJobCode(JobCode::E14);
        }
        else if (input.rfind("H", 2) == 2) {
            PrintByJobCode(JobCode::H14);
        }
        else if (input.rfind("T", 2) == 2) {
            PrintByJobCode(JobCode::T14);
        }
        else if (input.rfind("Z", 2) == 2) {
            PrintByJobCode(JobCode::Z14);
        }
        else if (input.rfind("K", 3) == 3) {
            PrintByJobCode(JobCode::K140);
        }
        else {
            cout << "Invalid Job Code\n\n" << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
        }
    }
    else if (input.rfind("2", 0) == 0 || input.rfind("5", 1 == 1)) {
        if (input.rfind("H", 2) == 2) {
            PrintByJobCode(JobCode::H25);
        }
        else {
            cout << "Invalid Job Code\n\n" << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>\n\n" << endl;
        }
    }
}

// Function that returns to the previous menu
void Roster::ReturnToMenu() {
    cin.ignore();
    cout << "Press enter to return to main menu\n\n";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    return;
}
// Destructor
    Roster::~Roster() {
        for (i = 0; i < numPersons; ++i) {
                delete rosterArray[i];
                rosterArray[i] = nullptr;
        }
}

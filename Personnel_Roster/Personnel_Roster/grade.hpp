//  Grade.h
//
//  Personnel_Roster
//
//  Created by Lauren Vazquez on 9/10/2022.
//
//  Enum class for all personnel grades
#pragma once

#include <string>

enum class Grade
{
    E1, E2, E3, E4, E5, E6, E7, WO1, CW2, CW3, O1, O2, O3
};

static const std::string GradeStrings[] =
{
    "E-1", "E-2", "E-3", "E-4", "E-5", "E-6", "E-7", "WO1", "CW2", "CW3", "O-1", "O-2", "O-3"
};

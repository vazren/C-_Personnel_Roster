//  job_code.h
//
//  Personnel_Roster
//
//  Created by Lauren Vazquez on 9/10/2022.
//
//  Enum class to set personnel gender
#pragma once

#include <string>

enum class Gender
{
    Male, Female, Unspecified
};

static const std::string GenderStrings[] =
{
    "Male", "Female", "Unspecified"
};

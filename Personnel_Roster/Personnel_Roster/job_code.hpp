//  job_code.h
//
//  Personnel_Roster
//
//  Created by Lauren Vazquez on 9/10/2022.
//
//  Enum class to set all job codes
#pragma once

#include <string>

enum class JobCode
{
    A14, E14, H14, H25, K140, T14, Z14, Other
};

static const std::string JobCodeStrings[] =
{
    "14A", "14E", "14H", "25H", "140K", "14T", "14Z", "Other"
};

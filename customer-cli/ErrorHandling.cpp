#include "ErrorHandling.h"
#include <algorithm>
#include <regex>

void isValidUserId(std::string input, Error& error, std::vector<int>& existingIds) 
{
    std::regex pattern("[0-9]+");
    if (! std::regex_match(input, pattern)) 
    {
        error.status = true;
        error.message = "Error: Invalid ID | Valid: Positiv und Numerische [0-9]";
    }
    else 
    {
        
        auto it = std::find(existingIds.begin(), existingIds.end(), std::stoi(input)); 
        if(it != existingIds.end())
        {
            error.status = true;
            error.message = "Error: Duplicate ID | Valid: Unique ID";
        }

    }
}

void isValidName(const std::string& input, Error& error) 
{
    std::regex pattern("([a-zA-ZäÄüÜöÖß]|\\s)+");
    if (! std::regex_match(input, pattern)) 
    {
        error.status = true;
        error.message = "Error: Invalid Name | Valid: nur Alphanumerische [A-Z]";
    }
}

void isValidZipCode(const std::string& input, Error& error) 
{
    std::regex pattern("[0-9]+");
    if (! std::regex_match(input, pattern) || (input.size() != MAX_ZIP_CODE_LENGTH)) 
    {
        error.status = true;
        error.message = "Error: Invalid Zipcode | Valid: nur Positiv, Numerische und 5 Zahl";
    }
}

void isValidColor(const std::string& input, Error& error) 
{
    const std::vector<std::string> validColors {
        "blue", "green", "violet", "red", "yellow", "turquoise", "white",
        "Blue", "Green", "Violet", "Red", "Yellow", "Turquoise", "White"
    };
    auto it = std::find_if(validColors.begin(), validColors.end(),[&input](std::string color){ return color == input; });
    if(it == validColors.end())
    {
        error.status = true;
        error.message = "Error: Invalid Farbe | Valid: nur blue, green, violet, red, yellow, turquoise, white";
    }
}

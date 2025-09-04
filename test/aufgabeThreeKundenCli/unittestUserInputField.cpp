#include "customer.h"
#include "KundenArchiv.h"
#include "ErrorHandling.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <vector>


namespace
{
TEST(KonsoleAnwendungUserInput, FieldValidationCustomerID)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Überprüfung, wenn der Benutzer eine falsche ID eingibt
    std::vector<int> kundenIds;
    for(const auto& ref: std::vector<std::string>{"-1", "asda", "&§98","","_"})
    {   
        Error error;
        isValidUserId(ref, error, kundenIds);
        EXPECT_EQ(error.status, true);
    } 
    // Test case: Überprüfung, wenn der Benutzer die richtige ID eingibt
    for(const auto& ref: std::vector<std::string>{"0", "112", "2332323","000","22322213"})
    {   
        Error error;
        isValidUserId(ref, error, kundenIds);
        EXPECT_EQ(error.status, false);
    }     
}

TEST(KonsoleAnwendungUserInput, FieldValidationCityAndCustomerNames)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Überprüfung, wenn der Benutzer eine falsche Namen bzw. first_name, last_name, city eingibt
    for(const auto& ref: std::vector<std::string>{"&Wrongname", "_asda", "M002","My_NAmE",""})
    {   
        Error error;
        isValidName(ref, error);
        EXPECT_EQ(error.status, true);
    } 
    // Test case: Überprüfung, wenn der Benutzer die richtige Namen bzw. first_name, last_name, city eingibt
    for(const auto& ref: std::vector<std::string>{"James", "Karl Von Ulm", "MXY","Andy","Livia"})
    {   
        Error error;
        isValidName(ref, error);
        EXPECT_EQ(error.status, false);
    }     
}

TEST(KonsoleAnwendungUserInput, FieldValidationZipCodes)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Überprüfung, wenn der Benutzer eine falsche PLZ-nummer eingibt
    for(const auto& ref: std::vector<std::string>{"12§ewq", "2312w", "1","123456","1234"})
    {   
        Error error;
        isValidZipCode(ref, error);
        EXPECT_EQ(error.status, true);
    } 
    // Test case: Überprüfung, wenn der Benutzer der richtige PLZ-nummer eingibt
    for(const auto& ref: std::vector<std::string>{"12345", "23451"})
    {   
        Error error;
        isValidZipCode(ref, error);
        EXPECT_EQ(error.status, false);
    }     
}

TEST(KonsoleAnwendungUserInput, FieldValidationFavoriteColor)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Überprüfung, wenn der Benutzer eine falsche Farbe eingibt
    for(const auto& ref: std::vector<std::string>{"Black", "Grey", "Rot", "Blur"})
    {   
        Error error;
        isValidColor(ref, error);
        EXPECT_EQ(error.status, true);
    } 
    // Test case: Überprüfung, wenn der Benutzer der richtige Farbe eingibt
    for(const auto& ref: std::vector<std::string>{"Yellow", "Blue", "green"})
    {   
        Error error;
        isValidColor(ref, error);
        EXPECT_EQ(error.status, false);
    }     
}

TEST(KonsoleAnwendungUserInput, FieldValidationDuplicateIDs)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Überprüfung, wenn der Benutzer ID schon existiert
    std::vector<int> kundenIds;
    for(const auto& ref: std::vector<std::string>{"1", "1", "2", "2"})
    {   
        Error error;
        isValidUserId(ref, error, kundenIds);
        if(! error.status) // Only add ids that are unique
            kundenIds.push_back(std::stoi(ref));
    } 
    EXPECT_EQ(kundenIds.size(), 2);
    EXPECT_EQ(kundenIds.at(0), 1);
    EXPECT_EQ(kundenIds.at(1), 2);
    // Test case: Überprüfung, wenn es keine doppelte Benutzer ID gibt
    for(const auto& ref: std::vector<std::string>{{"4", "5", "3", "100"}})
    {   
        Error error;
        isValidUserId(ref, error, kundenIds);
        kundenIds.push_back(std::stoi(ref));
    }   
    EXPECT_EQ(kundenIds.size(), 6);
    EXPECT_EQ(kundenIds.at(2), 4);
    EXPECT_EQ(kundenIds.at(3), 5);
    EXPECT_EQ(kundenIds.at(4), 3);
    EXPECT_EQ(kundenIds.at(5), 100);  
}
}
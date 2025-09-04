/**
 * 
 * @file Konsole Anwendung: Kundendaten
 * 
 * 
 */


#include "KundenDaten.h"
#include "customer.h"
#include "ErrorHandling.h"
#include <iostream>

/// @brief Konvertierung der vom Benutzer gewünschten Farbe 
///         in ein CUSTOMER datentypkompatibles Feld
/// @param input Name der Lieblingsfarbe 
void colorCode(std::string& input) 
{
    switch(std::tolower(input.at(0)))
    {
    case 'b':
        input = std::to_string(COLOR_BLUE); break;
    case 'g':
        input = std::to_string(COLOR_GREEN); break;
    case 'v':
        input = std::to_string(COLOR_VIOLET); break;
    case 'r':
        input = std::to_string(COLOR_RED); break;
    case 'y':
        input = std::to_string(COLOR_YELLOW); break;
    case 't':
        input = std::to_string(COLOR_TURQUOISE); break;
    case 'w':
        input = std::to_string(COLOR_WHITE); break;
    }
}

/// @brief Getter für CUSTOMER: id, first_name, last_name, zip_code, city, favorite_color 
/// @param fields Labels für CUSTOMER Felder
/// @param customer CUSTOMER: id, first_name, last_name, zip_code, city, favorite_color
/// @param exitingIds Liste der IDs, die bereits existieren
void userInput(const std::vector<std::string>& fields, CUSTOMER& customer, std::vector<int>& exitingIds)
{
    for(int id{0}; id < (int)fields.size(); ++id)
    {   
        bool errorDuringValidation = false;
        std::string input;
        do 
        {
            Error error; 
            std::cout << fields[id]; 
            std::getline(std::cin, input);
            switch(id)
            {
                case FIELD_ID:
                    isValidUserId(input, error, exitingIds); 
                    break;
                case FIELD_FIRST_NAME: case FIELD_LAST_NAME: case FIELD_CITY: 
                    isValidName(input, error); 
                    break;
                case FIELD_ZIP_CODE:    
                    isValidZipCode(input, error); 
                    break;
                case FIELD_COLOR:
                    isValidColor(input, error);
                    break;
            }
            if(error.status) // Wenn ein felher passiert ist, reset input field
            {    
                std::cout << error.message << std::endl;
                input.erase();
            }
            errorDuringValidation = error.status;
        } 
        while (errorDuringValidation); 
        if(id == FIELD_ID)    
            exitingIds.push_back(std::stoi(input));
        if (id == FIELD_COLOR)
            colorCode(input);
        customer.insert(id, input);
    }      
}

/// @brief Kundendaten für die Gesamtzahl der Kunden
/// @param customers: Klassen mit funktionen Kunden Archiv, Daten formattierer und Daten Speichern 
void getKundenDaten(KundenDaten& customers, int MAX_CUSTOMERS)
{
    std::vector<int> exitingIds;
    const std::vector<std::string> fields {
        "Id: ", 
        "First Name: ",
        "Last Name: ",
        "Zip Code: ",
        "City: ",
        "Color: "
    };

    while (MAX_CUSTOMERS > 0)
    {
        std::cout << "Kunden daten hinfügen: \n-----" << std::endl;   
        CUSTOMER customer;
        userInput(fields, customer, exitingIds);
        customers.addCustomer(std::move(customer));    
        --MAX_CUSTOMERS;
        std::cout << "---" << std::endl;
    }    
}

/// @brief  Bietet dem Benutzer die Möglichkeit, Daten in einer Textdatei oder ins Cloud, Db zu speichern
/// @return Save verfahren string: Textdatei | Cloud | Db
std::string saveMethod()
{
    std::string saveType;
    std::cout << "Datei speichern in [ Textdatei | Cloud | Db ]: "; 
    std::getline(std::cin, saveType);
    if (saveType == "Textdatei" || saveType == "Cloud" || saveType == "Db")
    {   
        return saveType;
    }    
    return "Textdatei";
}

/// @brief Anwendungs entry point
int main(int args, char** argv) 
{ 
    int maxCustomers = 3; 
    if(args == 3)
    { 
        maxCustomers = std::stoi(std::string{std::move(*argv[2])});
    }
    std::string saveType{saveMethod()};
    KundenDaten customers{saveType};
    
    getKundenDaten(customers, maxCustomers);

    for(const auto& customer: customers.getCustomers())
    {
        std::cout << customers.customerDetail(customer.id) << std::endl;
    }

    customers.saveCustomerData();
    return 0;
}

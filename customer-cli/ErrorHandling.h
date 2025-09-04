/**
 * 
 * @file Konsole Anwendung: User Input validation 
 * 
 * 
 */


#ifndef __ERROR_HANDLING_H
#define __ERROR_HANDLING_H

#include <string>
#include <vector>

/// @brief maximale Länge der PLZ: Kann geändert werden
#define MAX_ZIP_CODE_LENGTH 5
#define	FIELD_ID            0
#define FIELD_FIRST_NAME    1
#define FIELD_LAST_NAME     2
#define FIELD_ZIP_CODE      3
#define FIELD_CITY          4
#define FIELD_COLOR         5


/// @brief Datentyp zur Erfassung von Feldüberprüfungswerten
struct Error
{
    bool status = false;
    std::string message = "";
};


/// @brief Validerung der KundenID; Valid ID: Nur numerisch und keine Duplikate 
/// @param input Ein Integer als KundenID
/// @param error Ein Datentyp, der zur Kontrolle eines gültigen KundenID verwendet wird
void isValidUserId(std::string input, Error& error, std::vector<int>& exitingIds);


/// @brief Validerung von first_name, last_name und City: Valid Data: Nur alphanumerische werte
/// @param input Ein string als CUSTOMER:first_name, CUSTOMER:last_name, CUSTOMER:city
/// @param error Datentyp, der zur Kontrolle eines gültigen Names verwendet wird
void isValidName(const std::string& input, Error& error);


/// @brief Validerung von PLZ
/// @param input String als CUSTOMER:zip_code
/// @param error Datentyp, der zur Kontrolle eines gültigen PLZ-nummer verwendet wird
void isValidZipCode(const std::string& input, Error& error);


/// @brief Validerung von Favorite Color 
/// @param input String als CUSTOMER:favorite_color
/// @param error Datentyp, der zur Kontrolle eines gültigen Colors verwendet wird
void isValidColor(const std::string& input, Error& error);


#endif // __ERROR_HANDLING_H
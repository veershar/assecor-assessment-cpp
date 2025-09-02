/**
*
* @file Data Formatterier Klasse für die Bibliothek Kundendaten
*
*/

#ifndef __DEFINED_CUSTOMER_DATA_FORMAT
#define __DEFINED_CUSTOMER_DATA_FORMAT

#include "customer.h"
#include "KundenArchiv.h"
#include <string>

/// @brief KundenDataFormatter: Kundendatenformat auf Basis: <Nachname>, <Vorname>, <Postleitzahl> <Stadt>, <Lieblingsfarbe>

class KundenDataFormatter
{
public:
    KundenDataFormatter(const KundenArchiv& dataArchiv);

    /// @brief Abhängig von Kunden ID, formatiert die Daten
    /// @param id: gültige Kunden ID 
    /// @return string: formatierte Kundendaten 
    const std::string& customerDetail(const unsigned int& id);

    /// @brief Statische Funktion, die eine Farb ID in String konveritert
    /// @param colorId: Integer wert für eine Farbe 
    /// @return string: Name einer Farbe 
    static std::string color(const unsigned int& colorId);

private:
    const KundenArchiv& mDataArchive;
    std::string mCustomerAsStr;
};

#endif // __DEFINED_CUSTOMER_DATA_FORMAT

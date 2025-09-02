/**
*
* @file Kunden Archiv Klasse für die Bibliothek Kundendaten
*
*/

#ifndef __DEFINED_KUNDEN_ARCHIVE
#define __DEFINED_KUNDEN_ARCHIVE

#include "customer.h"
#include <algorithm>
#include <vector>

/// @brief Kunden Archiv Klasse, die mit In-memory Datentyp arbeitet
///        Funktion: Kunden hinzufügen, alle Kunden ausgeben, Kundendaten 
///                  zu einer ID ausgeben   

class KundenArchiv
{
public:

    /// @brief Default constructor
    KundenArchiv();

    /// @brief Constructor call für anonoymous object
    KundenArchiv(std::vector<CUSTOMER>& customerlist);
    
    /// @brief Constructor call für eine Kundenliste die man 
    ///        aus einer Quelle wie Cloud, Textdatei oder DB bekommt
    KundenArchiv(std::vector<CUSTOMER>&& customerlist);

    /// @brief Neukunden hinfügen
    /// @param customer: Customer Datentyp auf refactored CUSTOMER.H header Basis 
    void addCustomer(const CUSTOMER customer);

    /// @brief Alle Kundeninformation als Liste 
    /// @return KundenDaten: Auflistung existiereter Kundendaten während der Laufzeit der Anwendung
    const std::vector<CUSTOMER>& getCustomers() const;

    /// @brief Kundendaten zu einer ID ausgeben
    /// @param id: gültige Kunden ID
    /// @return Refactored CUSTOMER Datatype: Kundendaten 
    const CUSTOMER& customerLookup(const int& id) const;

private:
    std::vector<CUSTOMER>& customers;
    std::vector<CUSTOMER> defaultList;    
    const CUSTOMER customerNotFound{-1};
};

#endif // __DEFINED_CUSTOMER_ARCHIVE 

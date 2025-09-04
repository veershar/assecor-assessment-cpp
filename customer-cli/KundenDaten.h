/**
 * 
 * @file  KundenDaten.h 
 * Ein Datentype die Klass KundenArchiv, KundenDataFormatter, KundenDatenSpeicher
 * knüpfst
 * 
 */


#ifndef __KUNDEN_DATA_H
#define __KUNDEN_DATA_H


#include <memory>
#include "KundenArchiv.h"
#include "KundenDataFormatter.h"
#include "interfaceDataSpeichern.h"


class KundenDaten
{
public:
    /// @brief Default Constructor
    KundenDaten(std::string saveType = "TextDatei");

    /// @brief 
    /// @param customerList: Eine Liste von Kunden, die von einer externen Quelle
    ///                      bereitgestellt wird 
    KundenDaten(std::vector<CUSTOMER>& customerList);

    /// @brief Ein Wrapper Method zum KundenArchiv::addCustomer
    void addCustomer(const CUSTOMER customer);

    /// @brief Ein Wrapper Method zum KundenArchiv::getCustomers
    const std::vector<CUSTOMER>& getCustomers() const;

    /// @brief Ein Wrapper Method zum KundenArchiv::customerLookup
    const CUSTOMER& customerLookup(const int& id) const;

    /// @brief Ein Wrapper Method zum KundenDataFormatter::customerDetail    
    const std::string& customerDetail(const int& id);
    
    /// @brief Ein Wrapper Methoden zum KundenSpeichern Klasse
    void saveCustomerData();

private:
    KundenArchiv mArchiv;
    KundenDataFormatter mFormatter;
    std::unique_ptr<KundenDataSpeichern> mDataSpeicher;
    std::string mSaveType;
};

#endif 
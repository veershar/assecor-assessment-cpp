/**
*
* @ file
* Description Unit test zur Entwicklung einer Konsoleanwendung
*
*/


#include "customer.h"
#include "KundenArchiv.h"
#include "KundenDataFormatter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <vector>



class KundenDatatemp
{
public:
    KundenDatatemp(std::vector<CUSTOMER>& customerList):
       mArchiv{customerList}, mFormatter{mArchiv}
    {
    }

    void addCustomer(const CUSTOMER customer)
    {
        mArchiv.addCustomer(customer);
    }

    const std::vector<CUSTOMER>& getCustomers() const 
    {
        return mArchiv.getCustomers();
    }

    const CUSTOMER& customerLookup(const int& id) const 
    {
        return mArchiv.customerLookup(id);
    }

    const std::string& customerDetail(const int& id) 
    {
       return mFormatter.customerDetail(id);
    }

    void saveCustomerData() 
    {
       
    }
    
private:
    KundenArchiv mArchiv;
    KundenDataFormatter mFormatter;
};


using ::testing::AtLeast;
namespace
{
TEST(KonsoleAnwendungKundenDaten, KundenDatenHinfugen)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Neu Kunde hinfügen
    
    std::vector<CUSTOMER> list{CUSTOMER{2, "James"}, CUSTOMER{3, "Karl"}, CUSTOMER{4, "Jamie"}};
    KundenDatatemp kundenDaten(list);
    kundenDaten.addCustomer(CUSTOMER{1, "Tom"});
    auto obj = kundenDaten.customerLookup(3);
    EXPECT_EQ(obj.first_name, "Karl");
}

TEST(KonsoleAnwendungKundenDaten, DateinKundenFragen)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Gesamt Kundendaten fragen
    
    std::vector<CUSTOMER> list{CUSTOMER{2, "James"}, CUSTOMER{3, "Karl"}, CUSTOMER{4, "Jamie"}};
    KundenDatatemp kundenDaten(list);
    kundenDaten.addCustomer(CUSTOMER{1, "Tom"});
    auto obj = kundenDaten.getCustomers();
    EXPECT_EQ(obj.size(), 4);
}

TEST(KonsoleAnwendungKundenDaten, Kundenlookup)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Kunden mit einem ID suchen
    
    std::vector<CUSTOMER> list{CUSTOMER{2, "James"}, CUSTOMER{3, "Karl"}, CUSTOMER{4, "Jamie"}};
    KundenDatatemp kundenDaten(list);
    kundenDaten.addCustomer(CUSTOMER{1, "Tom"});
    auto obj = kundenDaten.customerLookup(4);
    EXPECT_EQ(obj.first_name, "Jamie");
}

TEST(KonsoleAnwendungKundenDaten, DatenFormatted)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Kundendaten in einem bestimmten Format anzeigen
    
    std::vector<CUSTOMER> list{CUSTOMER{2, "James"}, CUSTOMER{3, "Karl"}, CUSTOMER{4, "Jamie"}};
    KundenDatatemp kundenDaten(list);
    kundenDaten.addCustomer(CUSTOMER{10, "Hans", "Müller", "677742", "Lauterecken", 1});
    EXPECT_EQ(kundenDaten.customerDetail(10), "Müller, Hans, 677742 Lauterecken, Blau");
}

TEST(KonsoleAnwendungKundenDaten, SaveKundenDaten)
{
    // Test Suite: Konsole Anwendung für Kunden Daten
    // Test case: Speichern Kundendaten
    
    std::vector<CUSTOMER> list{CUSTOMER{2}};
    KundenDatatemp kundenDaten(list);
    kundenDaten.saveCustomerData();
}
}

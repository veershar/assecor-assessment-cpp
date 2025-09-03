/**
*
* @ file
* Description Unit test zur Implimentierung einer Kundendaten Bibliothek
*
*/


#include "customer.h"
#include "KundenArchiv.h"
#include "KundenDataFormatter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>


namespace 
{
TEST(KundenDatenFormattierer, DataFormattedByGultigID)
{
    // Test suite: Bibliothek hat einen Kundendatenformatierer
    // Test case: Expected Format: <Nachname>, <Vorname>, <Postleitzahl> <Stadt>, <Lieblingsfarbe>
    KundenArchiv customerArchive;
    customerArchive.addCustomer(CUSTOMER{1,"James", "Web", "12345", "Berlin", COLOR_BLUE});
    customerArchive.addCustomer(CUSTOMER{2,"Hans", "Müller", "677742", "Lauterecken", COLOR_BLUE});
    customerArchive.addCustomer(CUSTOMER{3,"Don", "Dino", "12345", "Berlin", COLOR_RED});
    customerArchive.addCustomer(CUSTOMER{4,"Simu", "Walker", "32134", "Berlin", COLOR_VIOLET});
    customerArchive.addCustomer(CUSTOMER{5,"Simone", "Webb", "12345", "Berlin", COLOR_TURQUOISE});
    KundenDataFormatter formatter{customerArchive};
    const std::vector<std::string> expectedResult{
        "Web, James, 12345 Berlin, Blau",
        "Müller, Hans, 677742 Lauterecken, Blau",
        "Dino, Don, 12345 Berlin, Rot",
        "Walker, Simu, 32134 Berlin, Voilet",
        "Webb, Simone, 12345 Berlin, Türkis"
    };
    unsigned count{0};
    for(const auto& customer: customerArchive.getCustomers())
    {   
        EXPECT_EQ(expectedResult[count++], formatter.customerDetail(customer.id));   
    }
}

TEST(CustomerDataFormatter, DataFormattedByUngultigID)
{
    // Test suite: Bibliothek hat einen Kundendatenformatierer
    // Test case: Expected Format: "(kein kunde)"
    KundenArchiv customerArchive;
    customerArchive.addCustomer(CUSTOMER{1,"James", "Web", "12345", "Berlin", COLOR_BLUE});
    customerArchive.addCustomer(CUSTOMER{2,"Hans", "Müller", "677742", "Lauterecken", COLOR_BLUE});
    customerArchive.addCustomer(CUSTOMER{3,"Don", "Dino", "12345", "Berlin", COLOR_RED});
    customerArchive.addCustomer(CUSTOMER{4,"Simu", "Walker", "32134", "Berlin", COLOR_VIOLET});
    customerArchive.addCustomer(CUSTOMER{5,"Simone", "Webb", "12345", "Berlin", COLOR_TURQUOISE});
    KundenDataFormatter formatter{customerArchive};
    EXPECT_EQ("(kein Kunde)", formatter.customerDetail(10));
    EXPECT_EQ("(kein Kunde)", formatter.customerDetail(-10));
    EXPECT_EQ("(kein Kunde)", formatter.customerDetail(0));
    EXPECT_EQ("(kein Kunde)", formatter.customerDetail(6));
}
}

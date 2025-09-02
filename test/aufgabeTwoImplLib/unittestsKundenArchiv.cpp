/**
*
* @ file
* Description Unit test zur Implimentierung einer Kundendaten Bibliothek
*
*/


#include "customer.h"
#include "KundenArchiv.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>


namespace 
{
TEST(KundenDatenLibKlassKundenArchiv, BenutztNeuDatenStructure)
{
    // Test suite: Kundendaten Bibliothek mit KundenArchiv Klasse
    // Test case: Klasse benutzt die neue Datenstruktur
    KundenArchiv customerArchive{std::vector<CUSTOMER>{CUSTOMER{1,"James", "Web"}}};
    EXPECT_EQ(customerArchive.customerLookup(1).first_name, "James");
}

TEST(KundenDatenLibKlassKundenArchiv, KundenHinfügen)
{
    // Test suite: Kundendaten Bibliothek mit KundenArchiv Klasse
    // Test case: Kunden können hingefügt werden
    KundenArchiv customerArchive;
    CUSTOMER neuCustomer{1,"James", "Web", "12345", "Berlin", COLOR_BLUE};
    customerArchive.addCustomer(neuCustomer);
    EXPECT_EQ(customerArchive.getCustomers().size(), 1);
}

TEST(KundenDatenLibKlassKundenArchiv, AlleKundenAusgeben)
{
    // Test suite: Kundendaten Bibliothek mit KundenArchiv Klasse
    // Test case: Die gesamten gespeicherten Kundendaten zurück geben
    KundenArchiv customerArchive;
    customerArchive.addCustomer(CUSTOMER{1,"James", "Web", "12345", "Berlin", COLOR_BLUE});
    customerArchive.addCustomer(CUSTOMER{2,"Karl", "Mann", "12345", "Berlin", COLOR_GREEN});
    customerArchive.addCustomer(CUSTOMER{3,"Don", "Dino", "12345", "Berlin", COLOR_RED});
    customerArchive.addCustomer(CUSTOMER{4,"Simu", "Walker", "32134", "Berlin", COLOR_VIOLET});
    customerArchive.addCustomer(CUSTOMER{5,"Simone", "Webb", "12345", "Berlin", COLOR_TURQUOISE});
    const auto customers = customerArchive.getCustomers();
    EXPECT_EQ(customers.size(), 5);
}

TEST(KundenDatenLibKlassKundenArchiv, KundenDatenzuEinID)
{
    // Test suite: Kundendaten Bibliothek mit KundenArchiv Klasse
    // Test case: Für eine KundenID, Kundendaten aus Archiv ausgeben 
    KundenArchiv customerArchive;
    customerArchive.addCustomer(CUSTOMER{1,"James", "Web", "12345", "Berlin", COLOR_BLUE});
    customerArchive.addCustomer(CUSTOMER{2,"Karl", "Mann", "12345", "Berlin", COLOR_GREEN});
    customerArchive.addCustomer(CUSTOMER{3,"Doni", "Dino", "12345", "Berlin", COLOR_RED});
    customerArchive.addCustomer(CUSTOMER{4,"Simu", "Walker", "32134", "Berlin", COLOR_VIOLET});
    customerArchive.addCustomer(CUSTOMER{5,"Simone", "Webb", "12345", "Berlin", COLOR_TURQUOISE});
    const auto customer1 = customerArchive.customerLookup(1);
    const auto customer3 = customerArchive.customerLookup(3);
    EXPECT_EQ(customer1.first_name, "James");
    EXPECT_EQ(customer3.first_name, "Doni");
}


TEST(KundenDatenLibKlassKundenArchiv, CustomerLookupNonExistingIds)
{
    // Test suite: Kundendaten Bibliothek mit KundenArchiv Klasse
    // Test case: Für eine Kunden ID die nicht existiert: Markiert mit "-1" als ID <Annahme: ID ist positive Zahl>
    KundenArchiv customerArchive;
    customerArchive.addCustomer(CUSTOMER{764,"James", "Web", "12345", "Berlin", COLOR_BLUE});
    customerArchive.addCustomer(CUSTOMER{2,"Karl", "Mann", "12345", "Berlin", COLOR_GREEN});
    customerArchive.addCustomer(CUSTOMER{3,"Doni", "Dino", "12345", "Berlin", COLOR_RED});
    customerArchive.addCustomer(CUSTOMER{4,"Simu", "Walker", "32134", "Berlin", COLOR_VIOLET});
    customerArchive.addCustomer(CUSTOMER{5,"Simone", "Webb", "12345", "Berlin", COLOR_TURQUOISE});
    const auto customer1 = customerArchive.customerLookup(100);
    const auto customer2 = customerArchive.customerLookup(-100);
    const auto customer3 = customerArchive.customerLookup(100000);
    const auto customer4 = customerArchive.customerLookup(764);
    EXPECT_EQ(customer1.id, -1);
    EXPECT_EQ(customer2.id, -1);
    EXPECT_EQ(customer3.id, -1);
    EXPECT_EQ(customer4.id, 764);
    EXPECT_EQ(customer4.first_name, "James");
    EXPECT_EQ(customer4.last_name, "Web");
    EXPECT_EQ(customer4.zip_code, "12345");
    EXPECT_EQ(customer4.city, "Berlin");
    EXPECT_EQ(customer4.favorite_color, COLOR_BLUE);
}
}

/**
*
* @ file
* Description Unit tests for refactored customer.h
* Unit test framework: Google Tests
*/


#include "customer.h"
#include <gtest/gtest.h>
#include <stdio.h>


namespace 
{
TEST(CustomerHeaderCLegacyCode, PlainOldDataStrObjCreation)
{
    // Test suite "CustomerHeaderCLegacyCode" 
    // Test case: C-Code die mit refactored customer.h header funktionert. 
    // Existiert code muss nicht geändert werden 
    CUSTOMER obj = {1, "James", "Webb", "12345", "Somecity", COLOR_BLUE};
    EXPECT_EQ(1, obj.id);
    EXPECT_STREQ("James", obj.first_name);
    EXPECT_STREQ("Webb", obj.last_name);
    EXPECT_STREQ("12345", obj.zip_code);
    EXPECT_STREQ("Somecity", obj.city);
    EXPECT_EQ(COLOR_BLUE, obj.favorite_color);
} 
}


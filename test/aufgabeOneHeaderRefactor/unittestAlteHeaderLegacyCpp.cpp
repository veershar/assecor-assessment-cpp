/**
*
* @ file
* Description Unit tests for refactored customer.h
*
*/


#include "customer.h"
#include <gtest/gtest.h>

namespace 
{
TEST(CustomerHeaderCppLegacyCode, PlainOldDataStrObjCreation)
{
    // Test suite "CustomerHeaderCppLegacyCode" 
    // Test case: Cpp-Code die mit refactored customer.h header funktionert. 
    // Existiert code muss nicht geändert werden
    CUSTOMER obj = {1, "David", "Webb", "12345", "Somecity", COLOR_BLUE};
    EXPECT_EQ(1, obj.id);
    EXPECT_STREQ("David", obj.first_name);
    EXPECT_STREQ("Webb", obj.last_name);
    EXPECT_STREQ("12345", obj.zip_code);
    EXPECT_STREQ("Somecity", obj.city);
    EXPECT_EQ(COLOR_BLUE, obj.favorite_color);
} 
}


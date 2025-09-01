/**
*
* @ file
* Description Unit tests for refactored customer.h
*
*/


#include "customer.h"
#include <gtest/gtest.h>
#include <iostream>

namespace 
{
TEST(CustomerHeaderRefactor, ModernObjectCreation)
{
    // Test suite "CustomerHeaderRefactor" 
    // Test case: Obj initiation using C++11 and above
    CUSTOMER obj{};
    EXPECT_EQ(1, obj.id);
    EXPECT_EQ(COLOR_BLUE, obj.favorite_color);
}   

TEST(CustomerHeaderRefactor, DynamicArrayGrowth)
{
    // Test suite "CustomerHeaderRefactor" 
    // Test case: 
    CUSTOMER obj{};
    obj.first_name = "Some very Some very Some very Some very Some very";
    // Should fail in the Plain old data structure customer.h
    EXPECT_EQ("Some very Some very Some very Some very Some very", obj.first_name);
}    

TEST(CustomerHeaderRefactor, ModernObjectInitialization)
{
    // Test suite "CustomerHeaderRefactor" 
    // Test case: 
    CUSTOMER obj{2, "David", "Gz", "23421", "Gasd", COLOR_GREEN};
    EXPECT_EQ(2, obj.id);
    EXPECT_EQ("David", obj.first_name);
    EXPECT_EQ("Gz", obj.last_name);
    EXPECT_EQ("23421", obj.zip_code);
    EXPECT_EQ("Gasd", obj.city);
    EXPECT_EQ(COLOR_GREEN, obj.favorite_color);
}  

TEST(CustomerHeaderRefactor, ObjWithIncompleteFieldInput)
{
    // Test suite "CustomerHeaderRefactor" 
    // Test case: 
    CUSTOMER obj{2, "David", "Gz"};
    EXPECT_EQ(2, obj.id);
    EXPECT_EQ("David", obj.first_name);
    EXPECT_EQ("Gz", obj.last_name);
}

TEST(CustomerHeaderRefactor, CustomerObjCopiesAnother)
{
    // Test suite "CustomerHeaderRefactor" 
    // Test case: 
    CUSTOMER obj1{2, "David", "Gz", "23421", "Berlin", COLOR_VIOLET};
    CUSTOMER obj2{obj1};    
    EXPECT_EQ(obj1.id, obj2.id);
    EXPECT_EQ(obj1.first_name, obj2.first_name);
    EXPECT_EQ(obj1.last_name, obj2.last_name);
    EXPECT_EQ(obj1.zip_code, obj2.zip_code);
    EXPECT_EQ(obj1.city, obj2.city);
    EXPECT_EQ(obj1.favorite_color, obj2.favorite_color);
}

TEST(CustomerHeaderRefactor, CustomerObjMovesData)
{
    // Test suite "CustomerHeaderRefactor" 
    // Test case: 
    CUSTOMER obj1{2, "David", "Gz", "23421", "Berlin", COLOR_VIOLET};
    CUSTOMER obj2{std::move(obj1)};    
    EXPECT_EQ(0, obj1.id);
    EXPECT_EQ("", obj1.first_name);
    EXPECT_EQ("", obj1.last_name);
    EXPECT_EQ("", obj1.zip_code);
    EXPECT_EQ("", obj1.city);
    EXPECT_EQ(0, obj1.favorite_color);
}


TEST(CustomerHeaderRefactor, CustomerObjCopyAssignment)
{
    // Test suite "CustomerHeaderRefactor" 
    // Test case: 
    CUSTOMER obj1{2, "David", "Gz", "23421", "Berlin", COLOR_VIOLET};
    CUSTOMER obj2;
    obj2 = obj1;    
    EXPECT_EQ(obj1.id, obj2.id);
    EXPECT_EQ(obj1.first_name, obj2.first_name);
    EXPECT_EQ(obj1.last_name, obj2.last_name);
    EXPECT_EQ(obj1.zip_code, obj2.zip_code);
    EXPECT_EQ(obj1.city, obj2.city);
    EXPECT_EQ(obj1.favorite_color, obj2.favorite_color);
}

TEST(CustomerHeaderRefactor, CustomerObjMoveAssignment)
{
    // Test suite "CustomerHeaderRefactor" 
    // Test case: 
    CUSTOMER obj1{2, "David", "Gz", "23421", "Berlin", COLOR_VIOLET};
    CUSTOMER obj2;
    obj2 = std::move(obj1);    
    EXPECT_NE(obj1.id, obj2.id);
    EXPECT_NE(obj1.first_name, obj2.first_name);
    EXPECT_NE(obj1.last_name, obj2.last_name);
    EXPECT_NE(obj1.zip_code, obj2.zip_code);
    EXPECT_NE(obj1.city, obj2.city);
    EXPECT_NE(obj1.favorite_color, obj2.favorite_color);
}
}

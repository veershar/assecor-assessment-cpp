#ifndef __CUSTOMER_CXX_H
#define __CUSTOMER_CXX_H

#include <string>
#include <iostream>


/// @brief Refactored customer.h. 

struct _CUSTOMER_CXX
{
    _CUSTOMER_CXX(const int& id = 1,
                  const std::string& first_name = "",
                  const std::string& last_name = "",
                  const std::string& zip_code = "",
                  const std::string& city = "",
                  const int& favorite_color = 1):
        id{id},
        first_name{first_name},
        last_name{last_name},
        zip_code{zip_code},
        city{city},
        favorite_color{favorite_color}
    {
    }

    // Copy constructor 
    _CUSTOMER_CXX(const _CUSTOMER_CXX&  customer):
        _CUSTOMER_CXX{customer.id, customer.first_name, customer.last_name, customer.zip_code, customer.city, customer.favorite_color}
    {
    }

    // Move constructor
    _CUSTOMER_CXX(_CUSTOMER_CXX&& customer):
        _CUSTOMER_CXX{customer}
    {
        customer.id = 0;
        customer.first_name.erase();
        customer.last_name.erase();
        customer.zip_code.erase();
        customer.city.erase();
        customer.favorite_color = 0;
    }

    // Copy assignment
    _CUSTOMER_CXX& operator=(const _CUSTOMER_CXX& customer)
    {
        this->id = customer.id; 
        this->first_name = customer.first_name;
        this->last_name = customer.last_name;
        this->zip_code = customer.zip_code;
        this->city = customer.city;
        this->favorite_color = customer.favorite_color;
        return *this;
    }

    // move assignment
    _CUSTOMER_CXX& operator=(_CUSTOMER_CXX&& customer)
    {
        *this = customer;
        customer.id = 0;
        customer.first_name.erase();
        customer.last_name.erase();
        customer.zip_code.erase();
        customer.city.erase();
        customer.favorite_color = 0;
        return *this;
    }

    // Comparison operator overloading
    bool operator==(const _CUSTOMER_CXX& customer) const 
    { 
        return id == customer.id && 
                first_name == customer.first_name &&
                last_name == customer.last_name &&
                zip_code == customer.zip_code &&
                city == customer.city &&
                favorite_color == customer.favorite_color; 
    }

    // In Felder der Customer Datentyp, werte hinzufügen
    // wie Array indexing.
    void insert(int idx, std::string fieldValue)
    { 
        if(idx == 0)
        { 
            id = std::stoi(fieldValue);
        }
        else if (idx == 1)
        {
            first_name = fieldValue;
        }
        else if (idx == 2)
        {
            last_name = fieldValue;
        }
        else if (idx == 3)
        {
            zip_code = fieldValue;
        }
        else if (idx == 4)
        {
            city = fieldValue;
        }    
        else if (idx == 5)
        {
            favorite_color = std::stoi(fieldValue);
        }
    }

    
    int id;
    std::string first_name;
    std::string last_name;
    std::string zip_code;
    std::string city;
    int favorite_color;
};


#endif // endif __CUSTOMER_CXX_H

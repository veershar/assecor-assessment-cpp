#include "KundenArchiv.h"


KundenArchiv::KundenArchiv(): customers{defaultList}
{
}    
    
KundenArchiv::KundenArchiv(std::vector<CUSTOMER>& customerlist):
    customers{customerlist}
{        
}
    
KundenArchiv::KundenArchiv(std::vector<CUSTOMER>&& customerlist):
    customers{defaultList}
{        
    defaultList = customerlist;
}

void KundenArchiv::addCustomer(const CUSTOMER customer)
{
    customers.push_back(customer);        
}
     
const std::vector<CUSTOMER>& KundenArchiv::getCustomers() const 
{
    return customers;
}

const CUSTOMER& KundenArchiv::customerLookup(const int& id) const
{
    auto itrCustomerlist = std::find_if(
        customers.begin(), 
        customers.end(), 
        [&id](const CUSTOMER& customer){ return id == customer.id; 
    });
    
    if (itrCustomerlist == customers.end())
    {
        return customerNotFound;
    }
    return *itrCustomerlist;
}



#ifndef __CUSTOMER_DATA_SAVE
#define __CUSTOMER_DATA_SAVE

#include "customer.h"
#include <string>
#include <vector>

class KundenSpeichern
{
public:
    KundenSpeichern(std::vector<CUSTOMER> customers, std::string saveType);
private:
    std::vector<CUSTOMER> mCustomers;
    std::string mSaveType;
};


#endif

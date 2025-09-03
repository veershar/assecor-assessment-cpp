#include "KundenDaten.h"
#include "KundenSpeichern.h"

KundenDaten::KundenDaten(std::string saveType):
    mFormatter{mArchiv}, mSaveType{saveType} 
{
    if (mSaveType == "Db")
    {
        mDataSpeicher = std::make_unique<SpeichernDb>("MySQL-server-instance", "Qerty");
    }
    else if (mSaveType == "Cloud")
    {
        mDataSpeicher = std::make_unique<SpeichernCloud>("0.0.0.0:80");
    }
    else
    {
        mDataSpeicher = std::make_unique<SpeichernTextDatei>("kundenDatenMuster.txt");
    }
    
}

KundenDaten::KundenDaten(std::vector<CUSTOMER>& customerList):
    mArchiv{customerList}, mFormatter{mArchiv}
{
}

void KundenDaten::addCustomer(const CUSTOMER customer)
{
    mArchiv.addCustomer(customer);
}

const std::vector<CUSTOMER>& KundenDaten::getCustomers() const 
{
    return mArchiv.getCustomers();
}

const CUSTOMER& KundenDaten::customerLookup(const int& id) const 
{
    return mArchiv.customerLookup(id);
}

const std::string& KundenDaten::customerDetail(const int& id) 
{
    return mFormatter.customerDetail(id);
}

void KundenDaten::saveCustomerData() 
{   
    mDataSpeicher->save(mArchiv.getCustomers());
}

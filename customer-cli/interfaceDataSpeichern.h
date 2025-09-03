/**
 * 
 * @file  Interface zum Datenspeichern 
 * Es funktionert mit dem Cloud, Db oder Textfile specihern verfahren
 * 
 */

#ifndef __INTERFACE_KUNDEN_SPEICHERN
#define __INTERFACE_KUNDEN_SPEICHERN

#include "customer.h"
#include <vector>

class KundenDataSpeichern
{
public:
    virtual int open() = 0;
    virtual void save(const std::vector<CUSTOMER>& listCustomers) = 0;
    virtual void close() = 0;  
    virtual ~KundenDataSpeichern(){}
};

#endif // __INTERFACE_KUNDEN_SPEICHERN
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
#include <memory>



class iKundenDataSpeichern
{
public:
    virtual int open() = 0;
    virtual void save(const std::vector<CUSTOMER>& listCustomers) = 0;
    virtual void close(const int filedescriptor) = 0;    
    virtual ~iKundenDataSpeichern(){}
};

class KundenDataInText : public iKundenDataSpeichern
{
public:
    KundenDataInText(const std::string& filename=""):
        mFilename{filename}
    {
    }

    int open() override
    {
        std::cout << "Opening file for read/write operations." << std::endl;
        int filedescriptor = 1;
        return filedescriptor;
    }        

    void save(const std::vector<CUSTOMER>& listCustomers) override 
    {
        std::cout << "Saving data to text file" << std::endl;
    }

    void close(const int filedescriptor) override
    {
        std::cout << "Closing text file with FD: " << filedescriptor << std::endl;        
    } 

private:
    std::string mFilename;
};

class KundenDataInCloud : public iKundenDataSpeichern
{
public:
    KundenDataInCloud(const std::string& socket="", const std::string& config=""):
        mSocket{socket}, mConfig{config}
    {
    }
  
    int open() override
    {
        std::cout << "Establishing connection with the cloud" << std::endl;
        int connectionCode = connectToCloud();
        return connectionCode;
    }        

    void save(const std::vector<CUSTOMER>& listCustomers) override 
    {
        std::cout << "Writing data to cloud" << std::endl;
    }

    void close(const int filedescriptor) override
    {
        std::cout << "Closing the connection to the cloud with ID:  " << filedescriptor << std::endl;    
    }

    int connectToCloud() 
    {
        return 1;
    } 
private:
    std::string mSocket;
    std::string mConfig;
};

class KundenDataInDatenbank : public iKundenDataSpeichern
{
public:
    KundenDataInDatenbank(const std::string& dbname="", const std::string& password=""):
        mDbname{dbname}, mPassword{password}
    {
    }
  
    int open() override
    {
        std::cout << "Connecting to the Database: " << std::endl;
        int connectionCode = connectToDb();
        return connectionCode;
    }        

    void save(const std::vector<CUSTOMER>& listCustomers) override 
    {
        std::cout << "Saving to the database: " << std::endl;
    }

    void close(const int filedescriptor) override
    {
        std::cout << "Closing the Database connection with ID: " << filedescriptor << std::endl;
    }

    int connectToDb() 
    {
        return 1;
    } 
private:
    std::string mDbname;
    std::string mPassword;
};


class MockSaveCustomerData: public iKundenDataSpeichern
{
public:
    MOCK_METHOD(int, open, (), (override));
    MOCK_METHOD(void, save, (const std::vector<CUSTOMER>& listCustomers), (override));
    MOCK_METHOD(void, close, (const int filedescriptor), (override));
}; 

class KundenData
{
public:
    KundenData(const std::vector<CUSTOMER>& kundenData, iKundenDataSpeichern* saveData, iKundenDataSpeichern* mockObj):
        mKundenData{kundenData}, mSaveData{saveData}, mMockObj{mockObj}
    {
        int mFd = mSaveData->open(); 
        mMockObj->open();
    }

    void writeCustomerData()
    { 
        mMockObj->save(mKundenData);  
        if (mFd)
            mSaveData->save(mKundenData);           
    }   

    ~KundenData()
    {
        mMockObj->close(1);
        mSaveData->close(mFd);
    }

private:
    std::vector<CUSTOMER> mKundenData;
    iKundenDataSpeichern* mSaveData;
    iKundenDataSpeichern* mMockObj;
    int mFd;
};


using ::testing::AtLeast;

namespace 
{
TEST(MockDependencyKundenDatenSpeichernVerfahren, KundenDatenExtensionOpenFunktion)
{
    // Test Suite: 
    // Test Case: For textdatie, Db oder Cloud, open funktioned entweder erstellest ein filedescriptor, die mit dem standard output 
    // die verbindung etabiliert oder mit Cloud oder DB-Server Verbindung etabiliert
    KundenArchiv dataArchive;
    dataArchive.addCustomer(CUSTOMER{1,"James", "WEbb", "12345", "Berlin", COLOR_BLUE});
    dataArchive.addCustomer(CUSTOMER{2,"Mark", "Weber", "14532", "Bonn", COLOR_GREEN});
    std::vector<std::unique_ptr<iKundenDataSpeichern>> kundenDatenObject;
    kundenDatenObject.push_back(std::make_unique<KundenDataInText>("kundenDaten.txt"));
    kundenDatenObject.push_back(std::make_unique<KundenDataInCloud>("127.0.0.1:8080", "config.json"));
    kundenDatenObject.push_back(std::make_unique<KundenDataInDatenbank>("kundenDaten", "password"));    
   
    std::vector<CUSTOMER> listCustomers{dataArchive.getCustomers()};
    for (const auto& ob: kundenDatenObject)
    {
        MockSaveCustomerData obj;    
        EXPECT_CALL(obj, open()).Times(AtLeast(1));
        EXPECT_CALL(obj, save(listCustomers)).Times(AtLeast(1));
        EXPECT_CALL(obj, close(1)).Times(AtLeast(1));        
        KundenData customer(listCustomers, ob.get(), &obj);
        customer.writeCustomerData();    
    } 
}

}

/**
 * 
 * @file  Klassen zum dem Cloud, Db oder Textfile specihern verfahren
 * Nur Declaration, keine Konkrete Implementation von Klassen funktionen
 * 
 */


#ifndef __CUSTOMER_DATA_SAVE
#define __CUSTOMER_DATA_SAVE

#include "customer.h"
#include "interfaceDataSpeichern.h"
#include <string>
#include <vector>


/// @brief Kundendaten als Textdatien speichern
class SpeichernTextDatei: public KundenDataSpeichern
{
public: 
    SpeichernTextDatei(const std::string& filename=""):
        mFilename{filename}
    {
        mFileDescriptor = this->open();
    }

    int open() override 
    {
        std::cout << "Opening file for " << mFilename << " read/write operations." << std::endl;
        int filedescriptor = 1;
        return filedescriptor;
    }        

    void save(const std::vector<CUSTOMER>& listCustomers) override  
    {
        for(auto& customer: listCustomers)
        {
            std::cout << "Writing " << customer.id << ": " << customer.first_name << " to the textfile" << std::endl;
        }
    }

    void close() override
    {
        std::cout << "Closing text file with FD: " << mFileDescriptor << std::endl;        
    }

    ~SpeichernTextDatei()
    {
        this->close();
    }

private:
    std::string mFilename;
    int mFileDescriptor;
};


/// @brief Kundendaten ins Cloud speichern
class SpeichernCloud: public KundenDataSpeichern
{
public:
    SpeichernCloud(const std::string& socket="", const std::string& config=""):
        mSocket{socket}, mConfig{config}
    {
        this->open();
    }
  
    int open() override
    {
        std::cout << "Establishing connection with: " << mSocket << std::endl;
        int connectionCode = connectToCloud();
        return connectionCode;
    }        

    void save(const std::vector<CUSTOMER>& listCustomers) override
    {
        std::cout << "Writing data to cloud" << std::endl;
        for(auto& customer: listCustomers)
        {
            std::cout << "Uploading " << customer.id << ": " << customer.first_name << " to " << mSocket << std::endl;
        }
    }

    void close() override  
    {
        std::cout << "Closing the connection to the cloud" << std::endl;    
    }

    ~SpeichernCloud()
    {
        this->close();
    }

private:
    int connectToCloud() 
    {
        return 1;
    } 
    std::string mSocket;
    std::string mConfig;
};


/// @brief Kundendaten ins Datenbank speichern
class SpeichernDb: public KundenDataSpeichern
{
public:
    SpeichernDb(const std::string& dbname="", const std::string& password=""):
        mDbname{dbname}, mPassword{password}
    {
        this->open();
    }
  
    int open() override
    {
        std::cout << "Connecting to the Database: " << mDbname << std::endl;
        int connectionCode = connectToDb();
        return connectionCode;
    }        

    void save(const std::vector<CUSTOMER>& listCustomers) override   
    {
        for(auto& customer: listCustomers)
        {
            std::cout << "Saving " << customer.id << ": " << customer.first_name << " to the database" << std::endl;
        }
        
    }

    void close() override 
    {
        std::cout << "Closing the Database connection" << std::endl;
    }

    ~SpeichernDb() 
    {
        this->close();
    } 

private:
    int connectToDb() 
    {
        return 1;
    } 
    std::string mDbname;
    std::string mPassword;
};

#endif

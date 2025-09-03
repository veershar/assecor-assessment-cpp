#include "KundenDataFormatter.h"


KundenDataFormatter::KundenDataFormatter(const KundenArchiv& dataArchiv): 
    mDataArchive{dataArchiv}, mCustomerAsStr{""}
{        
}
    

const std::string& KundenDataFormatter::customerDetail(const unsigned int& id)
{
    auto customer = mDataArchive.customerLookup(id);
    if(customer.id == -1)
    {
        // Falls wenn kein Kunden gefunden ist
        mCustomerAsStr = "(kein Kunde)";
    }
    else 
    {
        mCustomerAsStr = customer.last_name + ", " +  
                         customer.first_name + ", " +                              
                         customer.zip_code + " " + 
                         customer.city + ", " + 
                         KundenDataFormatter::color(customer.favorite_color);  
    }
    return mCustomerAsStr;
}

std::string KundenDataFormatter::color(const unsigned int& colorId)
{
    switch (colorId)
    {
    case COLOR_BLUE:
        return "Blau";
    case COLOR_GREEN:
        return "Grün";
    case COLOR_VIOLET:
        return "Voilet";
    case COLOR_RED:
        return "Rot";
    case COLOR_YELLOW:
        return "Gelb";
    case COLOR_TURQUOISE:
        return "Türkis";
    case COLOR_WHITE:
        return "Weiss";
    default:
        return "No favorite color";
    }
}


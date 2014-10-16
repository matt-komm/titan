#ifndef __DATAACCESSOR_H__
#define __DATAACCESSOR_H__

#include <iostream>

namespace titan
{


//abstract class allowing to read/write arbitrary data
class DataAccessor
{
    protected:
    public:
        //Class();
        /*
        Class(const Class& c);
        Class(Class&& c);
        Class& operator=(const Class& c);
        Class& operator=(Class&& c);
        ~Class();
        */
        
        virtual ~DataAccessor()
        {
        }
};

}

#endif


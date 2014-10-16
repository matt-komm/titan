#ifndef __DATACONTAINER_H__
#define __DATACONTAINER_H__

namespace titan
{

//abstract class for containers containing data

class DataContainer
{
    protected:
    public:
        //DataContainer();
        /*
        Class(const Class& c);
        Class(Class&& c);
        Class& operator=(const Class& c);
        Class& operator=(Class&& c);
        ~Class();
        */
        virtual ~DataContainer()
        {
        }
};

}

#endif


#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

namespace titan
{

class DataAccessor;

class DynamicArray:
    public DataContainer
{
    protected:
        DataAccessor* _dataAccessor;
    public:
        DynamicArray(DataAccessor* dataAccessor):
            _dataAccessor(dataAccessor)
        {
        }
        /*
        Class(const Class& c);
        Class(Class&& c);
        Class& operator=(const Class& c);
        Class& operator=(Class&& c);
        ~Class();
        */
        virtual ~DynamicArray()
        {
        	delete _dataAccessor;
        }
};

}

#endif


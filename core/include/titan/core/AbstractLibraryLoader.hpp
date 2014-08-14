#ifndef __ABSTRACTLIBRARYLOADER_H__
#define __ABSTRACTLIBRARYLOADER_H__

#include <string>

namespace titan
{

class AbstractLibraryLoader
{
    protected:
    public:
		AbstractLibraryLoader()
    	{
    	}

        virtual ~AbstractLibraryLoader()
        {
        }

        virtual void loadLibrary(std::string file) = 0;
};

}

#endif

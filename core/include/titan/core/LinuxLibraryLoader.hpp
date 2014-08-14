#ifndef __LINUXLIBRARYLOADER_H__
#define __LINUXLIBRARYLOADER_H__

#include "titan/core/AbstractLibraryLoader.hpp"

#include <string>
#include <map>
#include <dlfcn.h>

namespace titan
{

class LinuxLibraryLoader:
	public AbstractLibraryLoader
{
    protected:
		typedef void (*init_function_type)(void);

		std::map<std::string,void*> _loadedLibHandles;
    public:
		LinuxLibraryLoader():
			AbstractLibraryLoader()
    	{

		}
        virtual ~LinuxLibraryLoader()
        {
        	//dlclose(lib_handle);
        }

        virtual void loadLibrary(std::string file)
        {
        	if (_loadedLibHandles.find(file)==_loadedLibHandles.end())
        	{
				void* lib_handle;
				char *error;
				lib_handle = dlopen(file.c_str(), RTLD_LAZY);
				if (!lib_handle)
				{
					throw "Error while opening file: '"+file+"': "+std::string(dlerror());
				}
				_loadedLibHandles[file]=lib_handle;

				//hides object-to-function cast from the compiler
				SharedMemory<void*,init_function_type> smemory(dlsym(lib_handle, "initialize"));
				init_function_type fn = smemory.get();
				if ((error = dlerror()) != NULL)
				{
					throw "Error while initializing file: '"+file+"': "+std::string(dlerror());
				}
				(*fn)();
        	}
        }
};

}

#endif


#ifndef __PLUGINFACTORY_H__
#define __PLUGINFACTORY_H__

#include "titan/core/Exception.hpp"
#include "titan/core/Plugin.hpp"
#include "titan/core/LibraryLoader.hpp"


#include <vector>
#include <map>
#include <string>

namespace titan
{

class PluginFactory
{
    protected:
        std::map<std::string, AbstractPlugin*> _producers;
        LibraryLoader _libLoader;
        PluginFactory();
    public:
        static PluginFactory* getInstance();
        std::vector<std::string> getRegisteredPluginNames();
        void registerPlugin(AbstractPlugin* producer);
        template<class BASECLASS> Plugin<BASECLASS>* getPlugin(std::string pluginName)
        {
            if (_producers.find(pluginName)!=_producers.end())
            {
                Plugin<BASECLASS>* plugin = dynamic_cast<Plugin<BASECLASS>*>(_producers[pluginName]);
                if (!plugin)
                {
                    titan_throw("plugin with name '",pluginName,"' is of type '",_producers[pluginName]->getPluginBaseName(),"'");
                }
                return plugin;
            }
            else
            {
                titan_throw("plugin with name '",pluginName,"' not found");
            }
        }
        void loadPluginsFromFile(std::string file);

        inline bool hasPlugin(std::string name)
        {
            return _producers.find(name) != _producers.end();
        }

        ~PluginFactory();
};

}

#endif


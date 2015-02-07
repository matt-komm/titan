#include "titan/core/PluginFactory.hpp"

namespace titan
{

PluginFactory::PluginFactory():
    _libLoader()
{
}

PluginFactory*  PluginFactory::getInstance()
{
    static PluginFactory factory;
    return &factory;
}

std::vector<std::string> PluginFactory::getRegisteredPluginNames()
{
    std::vector<std::string> list;
    for (auto it = _producers.begin(); it!= _producers.end(); ++it )
    {
        list.push_back(it->first);
    }
    return list;
}

void PluginFactory::registerPlugin(AbstractPlugin* producer)
{
    if (_producers.find(producer->getPluginName())==_producers.end())
    {
        _producers[producer->getPluginName()]=producer;
    }
    else
    {
        throw std::string("plugin with name '"+producer->getPluginName()+"' already loaded");
    }
}

void PluginFactory::loadPluginsFromFile(std::string file)
{
    _libLoader.loadLibrary(file);
}

PluginFactory::~PluginFactory()
{
}

}

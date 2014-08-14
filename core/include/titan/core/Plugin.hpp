#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include <vector>
#include <string>

#include <typeinfo>

namespace titan
{

class AbstractPlugin
{
	private:
		std::string _pluginName;
		std::string _pluginBaseName;
		const std::type_info* _pluginType;
		const std::type_info* _pluginBaseType;
	public:
		AbstractPlugin(std::string pluginName, std::string pluginBaseName, const std::type_info* pluginType, const std::type_info* pluginBaseType):
			_pluginName(pluginName),
			_pluginBaseName(pluginBaseName),
			_pluginType(pluginType),
			_pluginBaseType(pluginBaseType)
		{
		}

		inline std::string getPluginName() const
		{
			return _pluginName;
		}

		inline std::string getPluginBaseName() const
		{
			return _pluginBaseName;
		}

		inline const std::type_info& getPluginType() const
		{
			return *_pluginType;
		}

		inline const std::type_info& getPluginBaseType() const
		{
			return *_pluginBaseType;
		}

		virtual ~AbstractPlugin()
		{
		}
};


template<class BASECLASS>
class Plugin:
	public AbstractPlugin
{
	public:
		Plugin(std::string pluginName, std::string pluginBaseName, const std::type_info* pluginType):
			AbstractPlugin(pluginName, pluginBaseName, pluginType, &typeid(BASECLASS))
		{
		}

		virtual BASECLASS* create() = 0;
};

template<class BASECLASS, class USERCLASS>
class ConcretePlugin:
	public Plugin<BASECLASS>
{
	public:
		ConcretePlugin(std::string pluginName, std::string pluginBaseName):
			Plugin<BASECLASS>(pluginName, pluginBaseName, &typeid(USERCLASS))
		{
		}

		virtual BASECLASS* create()
		{
			return new USERCLASS();
		}
};

}

#endif


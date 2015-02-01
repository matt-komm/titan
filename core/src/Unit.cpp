#include "titan/core/Unit.hpp"

#include <sstream>
#include <functional>

namespace titan
{

uint64 Unit::hash::operator()(const Unit& u) const
{
    uint64 h = 0;
    int n=1;
    for (std::map<std::string,int32>::const_iterator it =u._units.cbegin(); it != u._units.cend();++it)
    {
        h+=std::hash<std::string>()(it->first)*n*it->second;
        ++n;
    }
    return h;
}


bool Unit::eq::operator()(const Unit& u1, const Unit& u2) const
{
    if (u1._units.size()!=u2._units.size())
    {
        return false;
    }
	return Unit::hash()(u1)==Unit::hash()(u2);
}

bool Unit::less::operator()(const Unit& u1, const Unit& u2) const
{
    return Unit::hash()(u1)<Unit::hash()(u2);
}

Unit::Unit()
{
}

Unit::Unit(std::string name,int32 power)
{
	_units[name]=power;
}

Unit::Unit(const Unit& unit):
	_units(unit._units)
{
}

Unit::Unit(Unit&& unit):
	_units(std::move(unit._units))
{
}

Unit& Unit::invert()
{
	for (std::map<std::string,int32>::const_iterator it =_units.cbegin(); it != _units.cend();++it)
	{
		_units[it->first]=-it->second;
	}
	return *this;
}

Unit Unit::invert() const
{
	Unit u;
	for (std::map<std::string,int32>::const_iterator it =_units.cbegin(); it != _units.cend();++it)
	{
		u._units[it->first]=-it->second;
	}
	return std::move(u);
}


Unit& Unit::operator=(const Unit& unit)
{
	_units.clear();
	for (std::map<std::string,int32>::const_iterator it =unit._units.cbegin(); it != unit._units.cend();++it)
	{
		_units[it->first]=it->second;
	}
	return *this;
}
Unit& Unit::operator=(Unit&& unit)
{
	_units.clear();
	_units=std::move(unit._units);
	return *this;
}

Unit Unit::operator*(const Unit& unit) const
{
	Unit result(*this);
	for (std::map<std::string,int32>::const_iterator it = unit._units.cbegin(); it!= unit._units.cend();++it)
	{
		if (result._units.find(it->first)!=result._units.cend())
		{
			int32& power = result._units[it->first];
			power+=it->second;
			if (power==0)
			{
				result._units.erase(it->first);
			}
		}
		else
		{
			result._units[it->first]=it->second;
		}
	}
	return std::move(result);
}

Unit Unit::operator/(const Unit& unit) const
{
	Unit result(*this);
	for (std::map<std::string,int32>::const_iterator it = unit._units.cbegin(); it!= unit._units.cend();++it)
	{
		if (result._units.find(it->first)!=result._units.cend())
		{
			int32& power = result._units[it->first];
			power-=it->second;
			if (power==0)
			{
				result._units.erase(it->first);
			}
		}
		else
		{
			result._units[it->first]=-it->second;
		}
	}
	return std::move(result);
}

Unit& Unit::operator*=(const Unit& unit)
{
	for (std::map<std::string,int32>::const_iterator it = unit._units.cbegin(); it!= unit._units.cend();++it)
	{
		if (_units.find(it->first)!=_units.cend())
		{
			int32& power = _units[it->first];
			power+=it->second;
			if (power==0)
			{
				_units.erase(it->first);
			}
		}
		else
		{
			_units[it->first]=it->second;
		}
	}
	return *this;
}

Unit& Unit::operator/=(const Unit& unit)
{
	for (std::map<std::string,int32>::const_iterator it = unit._units.cbegin(); it!= unit._units.cend();++it)
	{
		if (_units.find(it->first)!=_units.cend())
		{
			int32& power = _units[it->first];
			power-=it->second;
			if (power==0)
			{
				_units.erase(it->first);
			}
		}
		else
		{
			_units[it->first]=-it->second;
		}
	}
	return *this;
}

bool Unit::operator==(const Unit& unit) const
{
	for (std::map<std::string,int32>::const_iterator it = unit._units.cbegin(); it!= unit._units.cend();++it)
	{
		//check unit name
		if (_units.find(it->first)==_units.cend())
		{
			return false;
		}
		else
		{
			//check unit power
			if (_units.at(it->first)!=it->second)
			{
				return false;
			}
		}
	}
	return true;
}

std::string Unit::toString() const
{
	std::stringstream ss;
	for (std::map<std::string,int32>::const_iterator it = _units.cbegin(); it!= _units.cend();++it)
	{
		ss<<it->first<<"^"<<it->second<<"*";
	}
	std::string ret=ss.str();
	ret.erase(ret.end()-1,ret.end());
	return std::move(ret);
}

Unit::~Unit()
{
}

}


#include "titan/core/Unit.hpp"

#include <sstream>

namespace titan
{

bool Unit::cmp::operator()(const Unit& u1, const Unit& u2)
{
	for (std::map<std::string,int32>::const_iterator it1 =u1._units.begin(); it1 != u1._units.end();++it1)
	{
		std::map<std::string,int32>::const_iterator it2 = u2._units.find(it1->first);
		if (it2==u2._units.end())
		{
			return false;
		}
		if (it2->second!=it1->second)
		{
			return false;
		}
	}
	return true;
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
	for (std::map<std::string,int32>::const_iterator it =_units.begin(); it != _units.end();++it)
	{
		_units[it->first]=-it->second;
	}
	return *this;
}

Unit Unit::invert() const
{
	Unit u;
	for (std::map<std::string,int32>::const_iterator it =_units.begin(); it != _units.end();++it)
	{
		u._units[it->first]=-it->second;
	}
	return std::move(u);
}


Unit& Unit::operator=(const Unit& unit)
{
	_units.clear();
	for (std::map<std::string,int32>::const_iterator it =unit._units.begin(); it != unit._units.end();++it)
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
	for (std::map<std::string,int32>::const_iterator it = unit._units.begin(); it!= unit._units.end();++it)
	{
		if (result._units.find(it->first)!=result._units.end())
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
	for (std::map<std::string,int32>::const_iterator it = unit._units.begin(); it!= unit._units.end();++it)
	{
		if (result._units.find(it->first)!=result._units.end())
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
	for (std::map<std::string,int32>::const_iterator it = unit._units.begin(); it!= unit._units.end();++it)
	{
		if (_units.find(it->first)!=_units.end())
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
	for (std::map<std::string,int32>::const_iterator it = unit._units.begin(); it!= unit._units.end();++it)
	{
		if (_units.find(it->first)!=_units.end())
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
	for (std::map<std::string,int32>::const_iterator it = unit._units.begin(); it!= unit._units.end();++it)
	{
		//check unit name
		if (_units.find(it->first)==_units.end())
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
	for (std::map<std::string,int32>::const_iterator it = _units.begin(); it!= _units.end();++it)
	{
		ss<<it->first<<"^"<<it->second<<"*";
	}
	std::string ret=ss.str();
	ret.erase(ret.end()-1,ret.end());
	return ret;
}

Unit::~Unit()
{
}

}


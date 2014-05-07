#include "titan/core/Quantity.hpp"

#include <sstream>

namespace titan
{

Unit::Unit()
{
}

Unit::Unit(std::string name,int32 power)
{
	_units[name]=power;
}

Unit& Unit::operator*(const Unit& unit)
{
	for (std::map<std::string,int32>::const_iterator it = unit._units.begin(); it!= unit._units.end();++it)
	{
		if (_units.find(it->first)!=_units.end())
		{
			int32& power = _units[it->first];
			power+=it->second;
			if (power==0)
			{
				_units.erase(it);
			}
		}
		else
		{
			_units[it->first]=it->second;
		}
	}
	return *this;
}

Unit& Unit::operator/(const Unit& unit)
{
	for (std::map<std::string,int32>::const_iterator it = unit._units.begin(); it!= unit._units.end();++it)
	{
		if (_units.find(it->first)!=_units.end())
		{
			int32& power = _units[it->first];
			power-=it->second;
			if (power==0)
			{
				_units.erase(it);
			}
		}
		else
		{
			_units[it->first]=-it->second;
		}
	}
	return *this;
}

bool Unit::operator==(const Unit& unit)
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
			if (_units[it->first]!=it->second)
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

Quantity::Quantity()
{
}
Quantity::Quantity(float value, const Unit& unit)
{
	_values[unit]=value;
}
Quantity& Quantity::operator+(const Quantity& quantity)
{
	for (const_iterator it = quantity._values.begin(); it != quantity._values.end(); ++it)
	{
		if (_values.find(it->first)!=_values.end())
		{
			_values[it->first]+=it->second;
		}
		else
		{
			_values[it->first]=it->second;
		}
	}
	return *this;
}

Quantity& Quantity::operator-(const Quantity& quantity)
{
	for (const_iterator it = quantity._values.begin(); it != quantity._values.end(); ++it)
	{
		if (_values.find(it->first)!=_values.end())
		{
			_values[it->first]-=it->second;
		}
		else
		{
			_values[it->first]=-it->second;
		}
	}
	return *this;
}

Quantity& Quantity::operator*(float32 factor)
{
	for (const_iterator it = _values.begin(); it != _values.end(); ++it)
	{
		_values[it->first]*=factor;
	}
	return *this;
}

std::string Quantity::toString()
{
	std::stringstream ss;

	for (const_iterator it = _values.begin(); it != _values.end(); ++it)
	{
		ss<<it->second<<"*"<<it->first.toString()<<"+";
	}
	std::string ret=ss.str();
	ret.erase(ret.end()-1,ret.end());
	return ret;
}

Quantity::~Quantity()
{
}



Quantity operator*(float32 magnitude, const Unit& unit)
{
    return Quantity(magnitude,unit);
}

Quantity operator*(float32 factor, const Quantity& quantity)
{
    Quantity q(quantity);
    return q*factor;
}

}

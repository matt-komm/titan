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
    return u1._hashValue==u2._hashValue;
}

bool Unit::less::operator()(const Unit& u1, const Unit& u2) const
{
    return u1._hashValue<u2._hashValue;
}

Unit::Unit()
{
    updateHash();
}

Unit::Unit(std::string name,int32 power)
{
    _units[name]=power;
    updateHash();
}

Unit::Unit(const Unit& unit):
    _units(unit._units)
{

    updateHash();
}

Unit::Unit(Unit&& unit):
    _hashValue(unit._hashValue),
    _units(std::move(unit._units))
{
    unit.updateHash();
}

Unit& Unit::invert()
{
    for (std::map<std::string,int32>::const_iterator it =_units.cbegin(); it != _units.cend();++it)
    {
        _units[it->first]=-it->second;
    }
    updateHash();
    return *this;
}

Unit Unit::invert() const
{
    Unit u(*this);
    u.invert();
    return std::move(u);
}


Unit& Unit::operator=(const Unit& unit)
{
    _units.clear();
    for (std::map<std::string,int32>::const_iterator it =unit._units.cbegin(); it != unit._units.cend();++it)
    {
        _units[it->first]=it->second;
    }
    updateHash();
    return *this;
}
Unit& Unit::operator=(Unit&& unit)
{
    _units.clear();
    _units=std::move(unit._units);
    _hashValue=unit._hashValue;
    unit.updateHash();
    return *this;
}

Unit Unit::operator*(const Unit& unit) const
{
    Unit result(*this);
    result*=unit;
    return std::move(result);
}

Unit Unit::operator/(const Unit& unit) const
{
    Unit result(*this);
    result/=unit;
    return std::move(result);
}

Unit& Unit::operator*=(const Unit& unit)
{
    for (std::map<std::string,int32>::const_iterator it = unit._units.cbegin(); it!= unit._units.cend();++it)
    {
        std::map<std::string,int32>::iterator thisIt = _units.find(it->first);
        if (thisIt!=_units.end())
        {
            int32& power = _units[it->first];
            power+=it->second;
            if (power==0)
            {
                _units.erase(thisIt);
            }
        }
        else
        {
            _units[it->first]=it->second;
        }
    }
    updateHash();
    return *this;
}

Unit& Unit::operator/=(const Unit& unit)
{
    for (std::map<std::string,int32>::const_iterator it = unit._units.cbegin(); it!= unit._units.cend();++it)
    {
        std::map<std::string,int32>::iterator thisIt = _units.find(it->first);
        if (_units.find(it->first)!=_units.end())
        {
            int32& power = _units[it->first];
            power-=it->second;
            if (power==0)
            {
                _units.erase(thisIt);
            }
        }
        else
        {
            _units[it->first]=-it->second;
        }
    }
    updateHash();
    return *this;
}


std::string Unit::toString() const
{
    if (_units.size()==0)
    {
        return "";
    }
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


#ifndef __UNIT_H__
#define __UNIT_H__

#include "titan/core/Types.hpp"

#include <map>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <functional>


namespace titan
{

class Unit
{
    protected:
        std::map<std::string,int32> _units;
    public:
        class cmp
        {
        	public:
				inline bool operator()(const Unit& u1, const Unit& u2)
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

        };
        Unit();
        Unit(std::string name,int32 power=1);
        inline bool isScalar()
        {
        	return _units.empty();
        }
        inline int32 getPower(std::string unitName)
        {
        	std::map<std::string,int32>::const_iterator it = _units.find(unitName);
        	if (it==_units.end())
        	{
        		return 0;
        	}
        	return _units[unitName];
        }
        Unit& operator*(const Unit& unit);
        Unit& operator/(const Unit& unit);
        Unit& operator*=(const Unit& unit);
        Unit& operator/=(const Unit& unit);
        bool operator==(const Unit& unit) const;
        std::string toString() const;
        ~Unit();
};

class SingleQuantity
{
    protected:
        float32 _value;
        Unit _unit;
    public:
        SingleQuantity():
            _value(0.0),
            _unit("")  
        {
        }
        SingleQuantity(float32 value, const Unit& unit):
            _value(value),
            _unit(unit)
        {
        }
        SingleQuantity& operator*(float32 factor)
        {
            _value*=factor;
            return *this;
        }
        SingleQuantity& operator/(float32 factor)
        {
            _value/=factor;
            return *this;
        }
        SingleQuantity& operator*(const Unit& unit)
        {
            _unit*=unit;
            return *this;
        }
        SingleQuantity& operator/(const Unit& unit)
        {
            _unit/=unit;
            return *this;
        }
        SingleQuantity& operator*=(float32 factor)
        {
            _value*=factor;
            return *this;
        }
        SingleQuantity& operator/=(float32 factor)
        {
            _value/=factor;
            return *this;
        }
        SingleQuantity& operator*=(const Unit& unit)
        {
            _unit*=unit;
            return *this;
        }
        SingleQuantity& operator/=(const Unit& unit)
        {
            _unit/=unit;
            return *this;
        }

        SingleQuantity& operator*(const SingleQuantity& sq)
		{
			_value*=sq.getValue();
			_unit*=sq.getUnit();
			return *this;
		}
		SingleQuantity& operator/(const SingleQuantity& sq)
		{
			_value*=sq.getValue();
			_unit*=sq.getUnit();
			return *this;
		}
		SingleQuantity& operator*=(const SingleQuantity& sq)
		{
			_value*=sq.getValue();
			_unit*=sq.getUnit();
			return *this;
		}
		SingleQuantity& operator/=(const SingleQuantity& sq)
		{
			_value*=sq.getValue();
			_unit*=sq.getUnit();
			return *this;
		}


		SingleQuantity operator*(const SingleQuantity& sq) const
		{
			SingleQuantity tmp(*this);
			tmp._value*=sq.getValue();
			tmp._unit*=sq.getUnit();
			return std::move(tmp);
		}
		SingleQuantity operator/(const SingleQuantity& sq) const
		{
			SingleQuantity tmp(*this);
			tmp._value/=sq.getValue();
			tmp._unit/=sq.getUnit();
			return std::move(tmp);
		}
		SingleQuantity operator*=(const SingleQuantity& sq) const
		{
			SingleQuantity tmp(*this);
			tmp._value*=sq.getValue();
			tmp._unit*=sq.getUnit();
			return std::move(tmp);
		}
		SingleQuantity operator/=(const SingleQuantity& sq) const
		{
			SingleQuantity tmp(*this);
			tmp._value/=sq.getValue();
			tmp._unit/=sq.getUnit();
			return std::move(tmp);
		}


        inline const Unit& getUnit() const
        {
            return _unit;
        }
        inline float32 getValue() const
        {
            return _value;
        }
        inline float32& getValue()
        {
            return _value;
        }
        ~SingleQuantity()
        {
        }
};

class Quantity
{
    protected:
        std::vector<SingleQuantity> _singles;
    public:
        Quantity()
        {
        }
        Quantity(float32 value, const Unit& unit)
        {
            _singles.push_back(SingleQuantity(value,unit));
        }
        Quantity(const SingleQuantity& singleQuantity)
        {
            _singles.push_back(singleQuantity);
        }
        Quantity& operator+(const SingleQuantity& singleQuantity)
        {
            for (unsigned int i = 0; i < _singles.size(); ++i)
            {
                if (_singles[i].getUnit()==singleQuantity.getUnit())
                {
                    _singles[i].getValue()+=singleQuantity.getValue();
                    return *this;
                }
            }
            _singles.push_back(singleQuantity);
            return *this;
        }
        Quantity& operator-(const SingleQuantity& singleQuantity)
        {
            for (unsigned int i = 0; i < _singles.size(); ++i)
            {
                if (_singles[i].getUnit()==singleQuantity.getUnit())
                {
                    _singles[i].getValue()-=singleQuantity.getValue();
                    return *this;
                }
            }
            _singles.push_back(singleQuantity);
            return *this;
        }
        Quantity& operator+=(const SingleQuantity& singleQuantity)
        {
            for (unsigned int i = 0; i < _singles.size(); ++i)
            {
                if (_singles[i].getUnit()==singleQuantity.getUnit())
                {
                    _singles[i].getValue()+=singleQuantity.getValue();
                    return *this;
                }
            }
            _singles.push_back(singleQuantity);
            return *this;
        }
        Quantity& operator-=(const SingleQuantity& singleQuantity)
        {
            for (unsigned int i = 0; i < _singles.size(); ++i)
            {
                if (_singles[i].getUnit()==singleQuantity.getUnit())
                {
                    _singles[i].getValue()-=singleQuantity.getValue();
                    return *this;
                }
            }
            _singles.push_back(singleQuantity);
            return *this;
        }
        Quantity& operator+(const Quantity& quantity)
        {
            for (unsigned int i = 0; i < quantity._singles.size(); ++i)
            {
                *this+=quantity._singles[i];
            }
            return *this;
        }
        Quantity& operator-(const Quantity& quantity)
        {
            for (unsigned int i = 0; i < quantity._singles.size(); ++i)
            {
                *this-=quantity._singles[i];
            }
            return *this;
        }
        Quantity& operator*(float32 factor)
        {
            for (unsigned int i = 0; i < _singles.size(); ++i)
            {
                _singles[i]*=factor;
            }
            return *this;
        }
        Quantity& operator/(float32 factor)
        {
            for (unsigned int i = 0; i < _singles.size(); ++i)
            {
                _singles[i]/=factor;
            }
            return *this;
        }
        Quantity& operator*(const Unit& unit)
        {
            for (unsigned int i = 0; i < _singles.size(); ++i)
            {
                _singles[i]*=unit;
            }
            return *this;
        }
        Quantity& operator/(const Unit& unit)
        {
            for (unsigned int i = 0; i < _singles.size(); ++i)
            {
                _singles[i]/=unit;
            }
            return *this;
        }

        uint32 getNumberOfSingleQuantities() const
        {
        	return _singles.size();
        }

        const SingleQuantity& getSingleQuantity(uint32 index) const
        {
        	return _singles[index];
        }

        std::string toString();
        
        ~Quantity();
};


SingleQuantity operator*(float32 magnitude, const Unit& unit);
SingleQuantity operator*(float32 factor, const SingleQuantity& quantity);

Quantity operator+(const SingleQuantity& quantity1, const SingleQuantity& quantity2);
Quantity operator-(const SingleQuantity& quantity1, const SingleQuantity& quantity2);

Quantity operator+(const SingleQuantity& singleQuantity, Quantity& quantity);
Quantity operator-(const SingleQuantity& singleQuantity, Quantity& quantity);

static const SingleQuantity mm = 1.0*Unit("mm");
static const SingleQuantity cm = 10.0*Unit("mm");
static const SingleQuantity in = 25.4*Unit("mm");
static const SingleQuantity pt = 1.0/72.0*in;
static const SingleQuantity px = 1.0*Unit("px");
static const SingleQuantity dpi = 1.0/25.4*(Unit("px")/Unit("mm"));

}

#endif


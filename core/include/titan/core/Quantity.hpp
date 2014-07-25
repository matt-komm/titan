#ifndef __QUANTITY_H__
#define __QUANTITY_H__

#include "titan/core/Types.hpp"
#include "titan/core/Unit.hpp"

#include <map>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <functional>
#include <iostream>
#include <utility>

namespace titan
{

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
        SingleQuantity(const SingleQuantity& sq):
        	_value(sq._value),
        	_unit(sq._unit)
        {
        }
        SingleQuantity(SingleQuantity&& sq):
			_value(sq._value),
			_unit(std::move(sq._unit))
		{
		}

        SingleQuantity& operator=(const SingleQuantity& sq)
		{
        	_value=sq._value;
        	_unit=sq._unit;
        	return *this;
		}
        SingleQuantity& operator=(SingleQuantity&& sq)
		{
			_value=sq._value;
			_unit=std::move(sq._unit);
			return *this;
		}

        SingleQuantity operator*(float32 factor) const
        {
        	SingleQuantity sq(*this);
        	sq._value*=factor;
            return std::move(sq);
        }
        SingleQuantity operator/(float32 factor) const
        {
        	SingleQuantity sq(*this);
        	sq._value/=factor;
            return std::move(sq);
        }
        SingleQuantity operator*(const Unit& unit) const
        {
        	SingleQuantity sq(*this);
        	sq._unit*=unit;
        	return std::move(sq);
        }
        SingleQuantity operator/(const Unit& unit) const
        {
        	SingleQuantity sq(*this);
        	sq._unit/=unit;
            return std::move(sq);
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

        SingleQuantity operator*(const SingleQuantity& singleQuantity) const
		{
        	SingleQuantity sq(_value*singleQuantity.getValue(),_unit*singleQuantity._unit);
			return std::move(sq);
		}
		SingleQuantity operator/(const SingleQuantity& singleQuantity) const
		{
			SingleQuantity sq(_value/singleQuantity.getValue(),_unit/singleQuantity._unit);
			return std::move(sq);
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

		SingleQuantity operator*=(const SingleQuantity& sq) const
		{
			return std::move((*this)*sq);
		}
		SingleQuantity operator/=(const SingleQuantity& sq) const
		{
			return std::move((*this)/sq);
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
            _singles.push_back(std::move(SingleQuantity(value,unit)));
        }
        Quantity(const SingleQuantity& singleQuantity)
        {
            _singles.push_back(singleQuantity);
        }
        Quantity(const Quantity& quantity):
			_singles(quantity._singles)
		{
		}
        Quantity(Quantity&& quantity):
			_singles(std::move(quantity._singles))
		{
		}
        Quantity& operator=(const Quantity& quantity)
		{
        	_singles=quantity._singles;
			return *this;
		}
        Quantity& operator=(Quantity&& quantity)
		{
        	_singles=std::move(quantity._singles);
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
        Quantity operator+(const Quantity& quantity)
        {
        	Quantity q(*this);
            for (unsigned int i = 0; i < quantity._singles.size(); ++i)
            {
                q+=quantity._singles[i];
            }
            return std::move(q);
        }
        Quantity operator-(const Quantity& quantity)
        {
        	Quantity q(*this);
			for (unsigned int i = 0; i < quantity._singles.size(); ++i)
			{
				q-=quantity._singles[i];
			}
			return std::move(q);
        }

        Quantity operator*(float32 factor) const
        {
        	Quantity q(*this);
            for (unsigned int i = 0; i < q._singles.size(); ++i)
            {
                q._singles[i]*=factor;
            }
            return std::move(q);
        }
        Quantity operator/(float32 factor) const
        {
        	Quantity q(*this);
            for (unsigned int i = 0; i < q._singles.size(); ++i)
            {
            	q._singles[i]/=factor;
            }
            return std::move(q);
        }
        Quantity operator*(const Unit& unit) const
        {
        	Quantity q(*this);
            for (unsigned int i = 0; i < q._singles.size(); ++i)
            {
            	q._singles[i]*=unit;
            }
            return std::move(q);
        }
        Quantity operator/(const Unit& unit) const
        {
        	Quantity q(*this);
            for (unsigned int i = 0; i < q._singles.size(); ++i)
            {
            	q._singles[i]/=unit;
            }
            return std::move(q);
        }

        inline uint32 getNumberOfSingleQuantities() const
        {
        	return _singles.size();
        }

        inline const SingleQuantity& getSingleQuantity(uint32 index) const
        {
        	return _singles[index];
        }

        std::string toString();
        
        ~Quantity();
};


SingleQuantity operator*(float32 magnitude, const Unit& unit);
SingleQuantity operator/(float32 magnitude, const Unit& unit);
SingleQuantity operator*(float32 factor, const SingleQuantity& quantity);
SingleQuantity operator/(float32 factor, const SingleQuantity& quantity);

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


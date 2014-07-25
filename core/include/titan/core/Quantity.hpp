#ifndef __QUANTITY_H__
#define __QUANTITY_H__

#include "titan/core/Types.hpp"
#include "titan/core/Unit.hpp"
#include "titan/core/SingleQuantity.hpp"

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


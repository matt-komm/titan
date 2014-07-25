#include "titan/core/Quantity.hpp"

#include <sstream>

namespace titan
{


/*

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





/*
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

Quantity& Quantity::operator/(float32 factor)
{
	for (const_iterator it = _values.begin(); it != _values.end(); ++it)
	{
		_values[it->first]/=factor;
	}
	return *this;
}

Quantity& Quantity::operator*(const Unit& unit)
{
	std::map<Unit,float32,Unit::cmp> values;
	for (const_iterator it = _values.begin(); it != _values.end(); ++it)
	{
		Unit newunit = Unit(it->first)*unit;
		values[newunit]=it->second;
	}
	_values=values;
	return *this;
}

Quantity& Quantity::operator/(const Unit& unit)
{
	std::map<Unit,float32,Unit::cmp> values;
	for (const_iterator it = _values.begin(); it != _values.end(); ++it)
	{
		Unit newunit = Unit(it->first)/unit;
		values[newunit]=it->second;
	}
	_values=values;
	return *this;
}

*/
std::string Quantity::toString()
{
    if (_singles.size()==0)
    {
        return "<none>";
    }
	std::stringstream ss;
	for (unsigned int i = 0; i < _singles.size(); ++i)
	{
		ss<<_singles[i].getValue()<<"*"<<_singles[i].getUnit().toString()<<"+";
	}
	std::string ret=ss.str();
	ret.erase(ret.end()-1,ret.end());
	return ret;
}

Quantity::~Quantity()
{
}



SingleQuantity operator*(float32 magnitude, const Unit& unit)
{
    return std::move(SingleQuantity(magnitude,unit));
}

SingleQuantity operator/(float32 magnitude, const Unit& unit)
{
    return std::move(SingleQuantity(magnitude,unit.invert()));
}

SingleQuantity operator*(float32 factor, const SingleQuantity& quantity)
{
    SingleQuantity q(quantity);
    return std::move(q*factor);
}

SingleQuantity operator/(float32 factor, const SingleQuantity& quantity)
{
    SingleQuantity q(1.0/quantity.getValue(),quantity.getUnit().invert());
    return std::move(q*factor);
}

Quantity operator+(const SingleQuantity& quantity1, const SingleQuantity& quantity2)
{
    Quantity q(quantity1);
    return std::move(q+quantity2);
}

Quantity operator-(const SingleQuantity& quantity1, const SingleQuantity& quantity2)
{
    Quantity q(quantity1);
    return std::move(q-quantity2);
}

Quantity operator+(const SingleQuantity& singleQuantity, Quantity& quantity)
{
    return std::move(quantity+singleQuantity);
}

Quantity operator-(const SingleQuantity& singleQuantity, Quantity& quantity)
{
    return std::move(quantity-singleQuantity);
}



}

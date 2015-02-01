#include "titan/core/Quantity.hpp"

#include <sstream>

namespace titan
{

Quantity::Quantity()
{
}

Quantity::Quantity(float32 value, const Unit& unit)
{
	_singles.push_back(std::move(SingleQuantity(value,unit)));
}

Quantity::Quantity(const SingleQuantity& singleQuantity)
{
	_singles.push_back(singleQuantity);
}

Quantity::Quantity(const Quantity& quantity):
	_singles(quantity._singles)
{
}

Quantity::Quantity(Quantity&& quantity):
	_singles(std::move(quantity._singles))
{
}

Quantity& Quantity::operator=(const Quantity& quantity)
{
	_singles=quantity._singles;
	return *this;
}

Quantity& Quantity::operator=(Quantity&& quantity)
{
	_singles=std::move(quantity._singles);
	return *this;
}

Quantity Quantity::operator+(const SingleQuantity& singleQuantity) const
{
    Quantity result(*this);
    for (unsigned int i = 0; i < result._singles.size(); ++i)
    {
        if (result._singles[i].getUnit()==singleQuantity.getUnit())
        {
            result._singles[i].getValue()+=singleQuantity.getValue();
            return std::move(result);
        }
    }
    result._singles.push_back(singleQuantity);
    return std::move(result);
}

Quantity Quantity::operator-(const SingleQuantity& singleQuantity) const
{
    Quantity result(*this);
    for (unsigned int i = 0; i < result._singles.size(); ++i)
    {
        if (result._singles[i].getUnit()==singleQuantity.getUnit())
        {
            result._singles[i].getValue()-=singleQuantity.getValue();
            return std::move(result);
        }
    }
    result._singles.push_back(-1.0*singleQuantity);
    return std::move(result);
}

Quantity& Quantity::operator+=(const SingleQuantity& singleQuantity)
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

Quantity& Quantity::operator-=(const SingleQuantity& singleQuantity)
{
	for (unsigned int i = 0; i < _singles.size(); ++i)
	{
		if (_singles[i].getUnit()==singleQuantity.getUnit())
		{
			_singles[i].getValue()-=singleQuantity.getValue();
			return *this;
		}
	}
	_singles.push_back(-1.0*singleQuantity);
	return *this;
}

Quantity& Quantity::operator+=(const Quantity& quantity)
{
    if (this==&quantity)
    {
        (*this)*=2.0;
        return *this;
    }
    for (unsigned int i = 0; i < quantity._singles.size(); ++i)
    {
        _singles.push_back(quantity._singles[i]);
    }
    return *this;
}

Quantity& Quantity::operator-=(const Quantity& quantity)
{
    if (this==&quantity)
    {
        _singles.clear();
        return *this;
    }
    for (unsigned int i = 0; i < quantity._singles.size(); ++i)
    {
        _singles.push_back(-1.0*quantity._singles[i]);
    }
    return *this;
}

Quantity Quantity::operator+(const Quantity& quantity) const
{
	Quantity q(*this);
	q+=quantity;
	return std::move(q);
}

Quantity Quantity::operator-(const Quantity& quantity) const
{
	Quantity q(*this);
	q-=quantity;
	return std::move(q);
}

Quantity Quantity::operator*(float32 factor) const
{
	Quantity q(*this);
	for (unsigned int i = 0; i < q._singles.size(); ++i)
	{
		q._singles[i]*=factor;
	}
	return std::move(q);
}
Quantity Quantity::operator/(float32 factor) const
{
	Quantity q(*this);
	for (unsigned int i = 0; i < q._singles.size(); ++i)
	{
		q._singles[i]/=factor;
	}
	return std::move(q);
}
Quantity Quantity::operator*(const Unit& unit) const
{
	Quantity q(*this);
	for (unsigned int i = 0; i < q._singles.size(); ++i)
	{
		q._singles[i]*=unit;
	}
	return std::move(q);
}
Quantity Quantity::operator/(const Unit& unit) const
{
	Quantity q(*this);
	for (unsigned int i = 0; i < q._singles.size(); ++i)
	{
		q._singles[i]/=unit;
	}
	return std::move(q);
}

Quantity Quantity::operator*=(float32 factor)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]*=factor;
    }
    return *this;
}
Quantity Quantity::operator/=(float32 factor)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]/=factor;
    }
    return *this;
}
Quantity Quantity::operator*=(const Unit& unit)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]*=unit;
    }
    return *this;
}
Quantity Quantity::operator/=(const Unit& unit)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]/=unit;
    }
    return *this;
}

std::string Quantity::toString() const
{
    if (_singles.size()==0)
    {
        return "<none>";
    }
	std::stringstream ss;
	for (unsigned int i = 0; i < _singles.size(); ++i)
	{
		ss<<_singles[i].toString();
	}
	return std::move(ss.str());
}

void Quantity::shrink()
{
    std::map<Unit,SingleQuantity,Unit::less> shrinkMap;
    for (uint32 i = 0; i < _singles.size(); ++i)
    {
        const SingleQuantity& sq = _singles[i];
        std::map<Unit,SingleQuantity,Unit::less>::iterator it = shrinkMap.find(sq.getUnit());
        if (it!=shrinkMap.end())
        {
            it->second.getValue()+=sq.getValue();
        }
        else
        {
            shrinkMap[sq.getUnit()]=sq;
        }
    }
    _singles.clear();
    for (std::map<Unit,SingleQuantity,Unit::less>::const_iterator it = shrinkMap.cbegin(); it != shrinkMap.cend(); ++it)
    {
        if (it->second.getValue()!=0.0)
        {
            _singles.emplace_back(it->second);
        }
    }
}

Quantity::~Quantity()
{
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

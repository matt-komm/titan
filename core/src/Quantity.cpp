#include "titan/core/Quantity.hpp"

#include <sstream>

namespace titan
{

Quantity::Quantity():
    _hashValue(0)
{
}

Quantity::Quantity(float32 value, const Unit& unit)
{
    _singles.push_back(std::move(SingleQuantity(value,unit)));
    updateHash();
}

Quantity::Quantity(const SingleQuantity& singleQuantity)
{
    _singles.push_back(singleQuantity);
    updateHash();
}

Quantity::Quantity(const Quantity& quantity):
    _hashValue(quantity._hashValue),
    _singles(quantity._singles)
{
}

Quantity::Quantity(Quantity&& quantity):
    _hashValue(quantity._hashValue),
    _singles(std::move(quantity._singles))
{
    updateHash();
}

Quantity& Quantity::operator=(const Quantity& quantity)
{
    _hashValue=quantity._hashValue;
    _singles=quantity._singles;
    return *this;
}

Quantity& Quantity::operator=(Quantity&& quantity)
{
    _hashValue=quantity._hashValue;
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
    result.updateHash();
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
    result.updateHash();
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
    updateHash();
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
    updateHash();
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
        (*this)+=quantity._singles[i];
    }
    updateHash();
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
        (*this)-=quantity._singles[i];
    }
    updateHash();
    return *this;
}

Quantity Quantity::operator+(const Quantity& quantity) const
{
    Quantity q(*this);
    q+=quantity;
    q.updateHash();
    return std::move(q);
}

Quantity Quantity::operator-(const Quantity& quantity) const
{
    Quantity q(*this);
    q-=quantity;
    q.updateHash();
    return std::move(q);
}

Quantity Quantity::operator*(float32 factor) const
{
    Quantity q(*this);
    for (unsigned int i = 0; i < q._singles.size(); ++i)
    {
        q._singles[i]*=factor;
    }
    q.updateHash();
    return std::move(q);
}
Quantity Quantity::operator/(float32 factor) const
{
    Quantity q(*this);
    for (unsigned int i = 0; i < q._singles.size(); ++i)
    {
        q._singles[i]/=factor;
    }
    q.updateHash();
    return std::move(q);
}
Quantity Quantity::operator*(const Unit& unit) const
{
    Quantity q(*this);
    for (unsigned int i = 0; i < q._singles.size(); ++i)
    {
        q._singles[i]*=unit;
    }
    q.updateHash();
    return std::move(q);
}
Quantity Quantity::operator/(const Unit& unit) const
{
    Quantity q(*this);
    for (unsigned int i = 0; i < q._singles.size(); ++i)
    {
        q._singles[i]/=unit;
    }
    q.updateHash();
    return std::move(q);
}

Quantity& Quantity::operator*=(float32 factor)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]*=factor;
    }
    updateHash();
    return *this;
}
Quantity& Quantity::operator/=(float32 factor)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]/=factor;
    }
    updateHash();
    return *this;
}
Quantity& Quantity::operator*=(const Unit& unit)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]*=unit;
    }
    updateHash();
    return *this;
}
Quantity& Quantity::operator/=(const Unit& unit)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]/=unit;
    }
    updateHash();
    return *this;
}


Quantity Quantity::operator*(const SingleQuantity& singleQuantity) const
{
    Quantity result(*this);
    result*=singleQuantity;
    result.updateHash();
    return std::move(result);
}

Quantity Quantity::operator/(const SingleQuantity& singleQuantity) const
{
    Quantity result(*this);
    result/=singleQuantity;
    result.updateHash();
    return std::move(result);
}

Quantity& Quantity::operator*=(const SingleQuantity& singleQuantity)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]*=singleQuantity;
    }
    updateHash();
    return *this;
}

Quantity& Quantity::operator/=(const SingleQuantity& singleQuantity)
{
    for (unsigned int i = 0; i < _singles.size(); ++i)
    {
        _singles[i]/=singleQuantity;
    }
    updateHash();
    return *this;
}

bool Quantity::operator==(const Quantity& quantity) const
{
    return _hashValue==quantity._hashValue;
}

bool Quantity::operator!=(const Quantity& quantity) const
{
    return _hashValue!=quantity._hashValue;
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


const SingleQuantity* Quantity::findByUnit(const Unit& unit) const
{
    for (uint32 i = 0; i < _singles.size(); ++i)
    {
        if (_singles[i].getUnit()==unit)
        {
            return &_singles[i];
        }
    }
    return nullptr;
}

Quantity::~Quantity()
{
}





Quantity operator+(const SingleQuantity& quantity1, const SingleQuantity& quantity2)
{
    Quantity q(quantity1);
    q+=quantity2;
    return std::move(q);
}

Quantity operator-(const SingleQuantity& quantity1, const SingleQuantity& quantity2)
{
    Quantity q(quantity1);
    q-=quantity2;
    return std::move(q);
}

Quantity operator+(const SingleQuantity& singleQuantity, Quantity& quantity)
{
    Quantity q(quantity);
    q+=singleQuantity;
    return std::move(q);
}

Quantity operator-(const SingleQuantity& singleQuantity, Quantity& quantity)
{
    Quantity q(quantity);
    q-=singleQuantity;
    return std::move(q);
}

Quantity operator*(const SingleQuantity& singleQuantity, Quantity& quantity)
{
    Quantity q(quantity);
    q*=singleQuantity;
    return std::move(q);
}

Quantity operator/(const SingleQuantity& singleQuantity, Quantity& quantity)
{
    Quantity q(quantity);
    q/=singleQuantity;
    return std::move(q);
}

}

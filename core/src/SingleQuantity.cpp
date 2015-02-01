#include "titan/core/SingleQuantity.hpp"

namespace titan
{


SingleQuantity::SingleQuantity():
	_value(0.0),
	_unit("")
{
}

SingleQuantity::SingleQuantity(float32 value, const Unit& unit):
	_value(value),
	_unit(unit)
{
}

SingleQuantity::SingleQuantity(const SingleQuantity& singleQuantity):
	_value(singleQuantity._value),
	_unit(singleQuantity._unit)
{
}

SingleQuantity::SingleQuantity(SingleQuantity&& singleQuantity):
	_value(singleQuantity._value),
	_unit(std::move(singleQuantity._unit))
{
}

SingleQuantity& SingleQuantity::operator=(const SingleQuantity& singleQuantity)
{
	_value=singleQuantity._value;
	_unit=singleQuantity._unit;
	return *this;
}

SingleQuantity& SingleQuantity::operator=(SingleQuantity&& singleQuantity)
{
	_value=singleQuantity._value;
	_unit=std::move(singleQuantity._unit);
	return *this;
}

SingleQuantity SingleQuantity::operator*(float32 factor) const
{
	SingleQuantity result(*this);
	result._value*=factor;
	return std::move(result);
}

SingleQuantity SingleQuantity::operator/(float32 factor) const
{
	SingleQuantity result(*this);
	result._value/=factor;
	return std::move(result);
}

SingleQuantity SingleQuantity::operator*(const Unit& unit) const
{
	SingleQuantity result(*this);
	result._unit*=unit;
	return std::move(result);
}

SingleQuantity SingleQuantity::operator/(const Unit& unit) const
{
	SingleQuantity result(*this);
	result._unit/=unit;
	return std::move(result);
}

SingleQuantity SingleQuantity::operator*(const SingleQuantity& singleQuantity) const
{
	SingleQuantity result(_value*singleQuantity.getValue(),_unit*singleQuantity._unit);
	return std::move(result);
}

SingleQuantity SingleQuantity::operator/(const SingleQuantity& singleQuantity) const
{
	SingleQuantity result(_value/singleQuantity.getValue(),_unit/singleQuantity._unit);
	return std::move(result);
}

SingleQuantity& SingleQuantity::operator*=(const SingleQuantity& singleQuantity)
{
	_value*=singleQuantity.getValue();
	_unit*=singleQuantity.getUnit();
	return *this;
}

SingleQuantity& SingleQuantity::operator/=(const SingleQuantity& singleQuantity)
{
	_value/=singleQuantity.getValue();
	_unit/=singleQuantity.getUnit();
	return *this;
}

SingleQuantity SingleQuantity::operator*=(const SingleQuantity& singleQuantity) const
{
	SingleQuantity result(getValue()*singleQuantity.getValue(),getUnit()*singleQuantity.getUnit());
	return std::move(result);
}

SingleQuantity SingleQuantity::operator/=(const SingleQuantity& singleQuantity) const
{
	SingleQuantity result(getValue()/singleQuantity.getValue(),getUnit()/singleQuantity.getUnit());
	return std::move(result);
}

std::string SingleQuantity::toString() const
{
    char* buf = new char[11];
    if (_value<1000.0 && _value > 0.01)
    {
        sprintf(buf,"%+5.2f",_value);
    }
    else
    {
        sprintf(buf,"%+5.4E",_value);
    }
    std::string s(buf);
    delete buf;
    s+="*"+_unit.toString();
    return std::move(s);
}

SingleQuantity::~SingleQuantity()
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

}


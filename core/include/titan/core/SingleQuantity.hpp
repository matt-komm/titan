#ifndef __SINGLEQUANTITY_H__
#define __SINGLEQUANTITY_H__

#include "titan/core/Types.hpp"
#include "titan/core/Unit.hpp"

namespace titan
{

class SingleQuantity
{
    protected:
        float32 _value;
        Unit _unit;
    public:
        SingleQuantity();
        SingleQuantity(float32 value, const Unit& unit);
        SingleQuantity(const SingleQuantity& sq);
        SingleQuantity(SingleQuantity&& sq);

        SingleQuantity& operator=(const SingleQuantity& singleQuantity);
        SingleQuantity& operator=(SingleQuantity&& singleQuantity);

        SingleQuantity operator*(float32 factor) const;
        SingleQuantity operator/(float32 factor) const;
        SingleQuantity operator*(const Unit& unit) const;
        SingleQuantity operator/(const Unit& unit) const;


        SingleQuantity operator*(const SingleQuantity& singleQuantity) const;
		SingleQuantity operator/(const SingleQuantity& singleQuantity) const;
		SingleQuantity& operator*=(const SingleQuantity& singleQuantity);
		SingleQuantity& operator/=(const SingleQuantity& singleQuantity);
		SingleQuantity operator*=(const SingleQuantity& singleQuantity) const;
		SingleQuantity operator/=(const SingleQuantity& singleQuantity) const;

		std::string toString() const;

        ~SingleQuantity();

        inline SingleQuantity& operator*=(float32 factor)
		{
			_value*=factor;
			return *this;
		}
		inline SingleQuantity& operator/=(float32 factor)
		{
			_value/=factor;
			return *this;
		}
		inline SingleQuantity& operator*=(const Unit& unit)
		{
			_unit*=unit;
			return *this;
		}
		inline SingleQuantity& operator/=(const Unit& unit)
		{
			_unit/=unit;
			return *this;
		}

        inline const Unit& getUnit() const
		{
			return _unit;
		}
		inline float32 getValue() const
		{
			return _value;
		}

		inline Unit& getUnit()
		{
			return _unit;
		}

		inline float32& getValue()
		{
			return _value;
		}
};

SingleQuantity operator*(float32 magnitude, const Unit& unit);
SingleQuantity operator/(float32 magnitude, const Unit& unit);
SingleQuantity operator*(float32 factor, const SingleQuantity& quantity);
SingleQuantity operator/(float32 factor, const SingleQuantity& quantity);

static const SingleQuantity mm = 1.0*Unit("mm");
static const SingleQuantity cm = 10.0*Unit("mm");
static const SingleQuantity in = 25.4*Unit("mm");
static const SingleQuantity pt = 1.0/72.0*in;
static const SingleQuantity px = 1.0*Unit("px");
static const SingleQuantity dpi = 1.0/25.4*(Unit("px")/Unit("mm"));

}

#endif


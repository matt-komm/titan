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
					return u1.toString()<u2.toString();
				}
        };
        Unit();
        Unit(std::string name,int32 power=1);
        Unit& operator*(const Unit& unit);
        Unit& operator/(const Unit& unit);
        bool operator==(const Unit& unit);
        std::string toString() const;
        ~Unit();
};

class Quantity
{
    protected:

        std::map<Unit,float32,Unit::cmp> _values;
        typedef std::map<Unit,float32,Unit::cmp>::const_iterator const_iterator;
    public:
        Quantity();
        Quantity(float value, const Unit& unit);
        Quantity& operator+(const Quantity& quantity);
        Quantity& operator-(const Quantity& quantity);
        Quantity& operator*(float32 factor);
        std::string toString();
        ~Quantity();
};


Quantity operator*(float32 magnitude, const Unit& unit);
Quantity operator*(float32 factor, const Quantity& quantity);


static const Quantity mm = 1.0*Unit("mm");
static const Quantity cm = 10.0*Unit("mm");
static const Quantity in = 25.4*Unit("mm");
static const Quantity pt = 1.0/72.0*in;
static const Quantity px = 1.0*Unit("px");
static const Quantity dpi = 1.0/25.4*(Unit("px")/Unit("mm"));

}

#endif


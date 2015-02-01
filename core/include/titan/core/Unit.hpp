#ifndef __UNIT_H__
#define __UNIT_H__

#include "titan/core/Types.hpp"

#include <map>
#include <string>

namespace titan
{

class Unit
{
    protected:
        std::map<std::string,int32> _units;
    public:
        struct eq
        {
			bool operator()(const Unit& u1, const Unit& u2) const;
        };

        struct less
        {
            bool operator()(const Unit& u1, const Unit& u2) const;
        };

        struct hash
        {
            uint64 operator()(const Unit& u) const;
        };

        Unit();
        Unit(std::string name,int32 power=1);
        Unit(const Unit& unit);
		Unit(Unit&& unit);

        Unit& invert();
        Unit invert() const;

        Unit operator*(const Unit& unit) const;
        Unit operator/(const Unit& unit) const;
        Unit& operator*=(const Unit& unit);
        Unit& operator/=(const Unit& unit);
        bool operator==(const Unit& unit) const;

        Unit& operator=(const Unit& unit);
        Unit& operator=(Unit&& unit);

        std::string toString() const;

        ~Unit();

        inline bool isScalar()
        {
        	return _units.empty();
        }
        inline int32 getPower(std::string unitName) const
        {
        	std::map<std::string,int32>::const_iterator it = _units.find(unitName);
        	if (it!=_units.end())
        	{
        		return _units.at(unitName);
        	}
        	return 0;
        }
};

}

#endif

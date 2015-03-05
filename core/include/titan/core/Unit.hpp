#ifndef __UNIT_H__
#define __UNIT_H__

#include "titan/core/Types.hpp"
#include "titan/core/StreamInterface.hpp"

#include <map>
#include <string>

namespace titan
{

class Unit:
    public StreamInterface
{
    protected:
        uint64 _hashValue;
        std::map<std::string,int32> _units;

        inline void updateHash()
        {
            _hashValue=Unit::hash()(*this);
        }

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

        inline uint64 getHash() const
        {
            return _hashValue;
        }

        bool operator==(const Unit& unit) const
        {
            return _hashValue==unit._hashValue;
        }
        bool operator!=(const Unit& unit) const
        {
            return _hashValue!=unit._hashValue;
        }


        Unit& operator=(const Unit& unit);
        Unit& operator=(Unit&& unit);

        virtual std::string toString() const;

        ~Unit();

        inline bool isScalar() const
        {
            return _units.empty();
        }

        inline int32 getPower(std::string unitName) const
        {
            std::map<std::string,int32>::const_iterator it = _units.find(unitName);
            if (it!=_units.cend())
            {
                return it->second;
            }
            return 0;
        }
};

}

#endif

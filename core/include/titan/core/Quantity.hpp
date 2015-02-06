#ifndef __QUANTITY_H__
#define __QUANTITY_H__

#include "titan/core/Types.hpp"
#include "titan/core/Unit.hpp"
#include "titan/core/SingleQuantity.hpp"
#include "titan/core/StreamInterface.hpp"

#include <map>
#include <vector>
#include <string>

namespace titan
{


class Quantity:
    public StreamInterface
{
    protected:
        uint64 _hashValue;
        std::vector<SingleQuantity> _singles;

        inline void updateHash()
        {
            _hashValue=0;
            if (_singles.size()>0)
            {
                _hashValue=_singles[0].getHash();
                for (uint32 i = 1; i < _singles.size(); ++i)
                {
                    _hashValue|=_singles[i].getHash();
                }
            }
        }
    public:
        Quantity();
        Quantity(float32 value, const Unit& unit);
        Quantity(const SingleQuantity& singleQuantity);
        Quantity(const Quantity& quantity);
        Quantity(Quantity&& quantity);

        Quantity& operator=(const Quantity& quantity);
        Quantity& operator=(Quantity&& quantity);

        Quantity operator+(const SingleQuantity& singleQuantity) const;
        Quantity operator-(const SingleQuantity& singleQuantity) const;
        Quantity& operator+=(const SingleQuantity& singleQuantity);
        Quantity& operator-=(const SingleQuantity& singleQuantity);

        Quantity operator+(const Quantity& quantity) const;
        Quantity operator-(const Quantity& quantity) const;
        Quantity& operator+=(const Quantity& quantity);
        Quantity& operator-=(const Quantity& quantity);

        Quantity operator*(float32 factor) const;
        Quantity operator/(float32 factor) const;
        Quantity& operator*=(float32 factor);
        Quantity& operator/=(float32 factor);

        Quantity operator*(const Unit& unit) const;
        Quantity operator/(const Unit& unit) const;
        Quantity& operator*=(const Unit& unit);
        Quantity& operator/=(const Unit& unit);

        Quantity operator*(const SingleQuantity& singleQuantity) const;
        Quantity operator/(const SingleQuantity& singleQuantity) const;
        Quantity& operator*=(const SingleQuantity& singleQuantity);
        Quantity& operator/=(const SingleQuantity& singleQuantity);

        bool operator==(const Quantity& quantity) const;
        bool operator!=(const Quantity& quantity) const;

        virtual std::string toString() const;

        ~Quantity();

        inline uint64 getHash() const
        {
            return _hashValue;
        }

        inline uint32 getNumberOfSingleQuantities() const
        {
        	return _singles.size();
        }

        inline const SingleQuantity& getSingleQuantity(uint32 index) const
        {
        	return _singles[index];
        }

};



Quantity operator+(const SingleQuantity& quantity1, const SingleQuantity& quantity2);
Quantity operator-(const SingleQuantity& quantity1, const SingleQuantity& quantity2);

Quantity operator+(const SingleQuantity& singleQuantity, Quantity& quantity);
Quantity operator-(const SingleQuantity& singleQuantity, Quantity& quantity);

Quantity operator*(const SingleQuantity& singleQuantity, Quantity& quantity);
Quantity operator/(const SingleQuantity& singleQuantity, Quantity& quantity);



}

#endif


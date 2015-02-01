#ifndef __QUANTITY_H__
#define __QUANTITY_H__

#include "titan/core/Types.hpp"
#include "titan/core/Unit.hpp"
#include "titan/core/SingleQuantity.hpp"

#include <map>
#include <vector>
#include <string>

namespace titan
{


class Quantity
{
    protected:
        std::vector<SingleQuantity> _singles;
    public:
        Quantity();
        Quantity(float32 value, const Unit& unit);
        Quantity(const SingleQuantity& singleQuantity);
        Quantity(const Quantity& quantity);
        Quantity(Quantity&& quantity);

        Quantity& operator=(const Quantity& quantity);
        Quantity& operator=(Quantity&& quantity);
        Quantity& operator+=(const SingleQuantity& singleQuantity);
        Quantity& operator-=(const SingleQuantity& singleQuantity);
        Quantity& operator+=(const Quantity& quantity);
        Quantity& operator-=(const Quantity& quantity);
        Quantity operator+(const Quantity& quantity);
        Quantity operator-(const Quantity& quantity);

        Quantity operator*(float32 factor) const;
        Quantity operator/(float32 factor) const;
        Quantity operator*(const Unit& unit) const;
        Quantity operator/(const Unit& unit) const;

        std::string toString() const;

        ~Quantity();

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



}

#endif


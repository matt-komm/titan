#ifndef __COORDINATESYSTEM_H__
#define __COORDINATESYSTEM_H__

#include "titan/core/Types.hpp"
#include "titan/core/Quantity.hpp"
#include "titan/core/Exception.hpp"
#include "titan/drawing/Point.hpp"


namespace titan
{

class CoordinateSystem
{
    public:
        virtual void convert(QPoint& qPoint) const = 0;
        virtual ~CoordinateSystem()
        {
        }
};


class CartesianCoordinates2d:
    public CoordinateSystem
{
    protected:
        const SingleQuantity _nominator;
        const SingleQuantity _denominator;
    public:
        CartesianCoordinates2d(const SingleQuantity& nominator, const SingleQuantity& denominator):
            _nominator(nominator),_denominator(denominator)
        {
        }

        virtual void convert(QPoint& qPoint) const
        {
            if (qPoint.size()!=2)
            {
                titan_throw("BadArgument", "Point has to be of dimension 2.");
            }
            qPoint[0].substitute(_nominator,_denominator);
            qPoint[1].substitute(_nominator,_denominator);
        }
        virtual ~CartesianCoordinates2d()
        {
        }
};

}

#endif


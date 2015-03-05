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
        virtual const UPoint& getUnits() const = 0;
        virtual QPoint convert(const QPoint& qPoint) const = 0;
        virtual ~CoordinateSystem()
        {
        }
};


class CartesianCoordinates2d:
    public CoordinateSystem
{
    protected:
        const SQPoint _resolution;
        const SQPoint _center;
        const UPoint _units;

    public:
        CartesianCoordinates2d(const SQPoint& resolution, const SQPoint center):
            _resolution(resolution),
            _center(center),
            _units{{_resolution[0].getUnit(),_resolution[1].getUnit()}}
        {
            if (_resolution.size()!=2)
            {
                titan_throw("BadArgument", "SQPoint 'resolution' has to be of dimension 2");
            }
            if (_center.size()!=2)
            {
                titan_throw("BadArgument", "SQPoint 'center' has to be of dimension 2");
            }
        }

        virtual const UPoint& getUnits() const
        {
            return _units;
        }

        virtual QPoint convert(const QPoint& qPoint) const
        {
            if (qPoint.size()!=2)
            {
                titan_throw("BadArgument", "QPoint has to be of dimension 2");
            }
            const SingleQuantity* sqX = qPoint[0].findByUnit(_units[0]);
            const SingleQuantity* sqY = qPoint[1].findByUnit(_units[1]);

            QPoint result(2);
            if (sqX)
            {
                result[0]+=(*sqX+_center[0])/_resolution[0];
            }
            if (sqY)
            {
                result[1]+=(*sqY+_center[1])/_resolution[1];
            }
            return result;
        }
        virtual ~CartesianCoordinates2d()
        {
        }
};

}

#endif


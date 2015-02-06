#ifndef __COORDINATESYSTEM_H__
#define __COORDINATESYSTEM_H__

#include "titan/core/Types.hpp"
#include "titan/core/Quantity.hpp"
#include "titan/drawing/Point.hpp"


namespace titan
{

class CoordinateSystem
{
	public:
		virtual const PxPoint& toPixel(const SQPoint& sqPoint) const = 0;
		virtual ~CoordinateSystem()
		{
		}
};

/*
class CartesianCoordinates:
	public CoordinateSystem
{
	protected:
		const SingleQuantity _resolution;
	public:
		CartesianCoordinates(const SingleQuantity& resolution):
			_resolution(resolution)
		{
		}

		inline const Unit& getUnit() const
		{
		    return (_resolution).getUnit();
		}
		


		virtual const PxPoint& toPixel(const SQPoint& sqPoint) const
		{
			PxPoint result(sqPoint.size());
			for (uint32 idim = 0; idim < sqPoint.size(); ++idim)
			{
				const SingleQuantity& sq_result = sqPoint[idim]/_resolution;
				if (sq_result.getUnit()==Unit("px"))
				{
					result[idim]=sq_result.getValue();
				}
			}
			return result;
		}
		virtual ~CartesianCoordinates()
		{
		}
};

*/
}

#endif


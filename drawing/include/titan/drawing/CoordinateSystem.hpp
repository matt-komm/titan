#ifndef __COORDINATESYSTEM_H__
#define __COORDINATESYSTEM_H__

#include "titan/core/Quantity.hpp"
#include "titan/drawing/Point.hpp"

#include <array>

namespace titan
{

class CoordinateSystem
{
	public:
		virtual PxPoint toPixel(const QPoint& qPoint) = 0;
};

/*
template<uint32 N>
class CartesianCoordinates:
	public CoordinateSystem<N>
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
		
		inline const SingleQuantity& getResolution() const
		{
		    return _resolution;
		}

		virtual PxPoint<N> toPixel(const SPoint<N>& sqPoint)
		{
			PxPoint<N> result;
			for (uint32 idim = 0; idim < N; ++idim)
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
typedef CartesianCoordinates<2> CartesianCoordinates2d;
*/
}

#endif


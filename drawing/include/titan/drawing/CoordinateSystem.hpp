#ifndef __COORDINATESYSTEM_H__
#define __COORDINATESYSTEM_H__

#include "titan/core/Quantity.hpp"
#include "titan/drawing/Point.hpp"

#include <array>

namespace titan
{

template<uint32 N>
class CoordinateSystem
{
	public:
		virtual PxPoint<N> toPixel(const SPoint<N>& sqPoint) = 0;
};

template<uint32 N>
class CartesianCoordinates:
	public CoordinateSystem<N>
{
	protected:
		SingleQuantity _resolution;
	public:
		CartesianCoordinates(SingleQuantity resolution):
			_resolution(resolution)
		{
		}
		
		virtual const Unit& getUnit() const
		{
		    return (_resolution*px).getUnit();
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

}

#endif

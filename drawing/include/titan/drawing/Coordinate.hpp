#ifndef __COORDINATE_H__
#define __COORDINATE_H__

#include "titan/core/Quantity.hpp"

#include <array>

namespace titan
{

template<class TYPE, uint32 N>
class Point
{
	protected:
		std::array<TYPE,N> _x;
	public:
		Point()
		{
		}

		inline const TYPE& operator[](uint32 index) const
		{
			return _x[index];
		}

		inline TYPE& operator[](uint32 index)
		{
			return _x[index];
		}
};

template<uint32 N>
class QPoint:
	Point<Quantity,N>
{
};

template<uint32 N>
class PxPoint:
	Point<float32,N>
{
};

template<uint32 N>
class Coordinate
{
	public:
		Coordinate();
		virtual PxPoint<N> toPixel(const QPoint<N>& quantity) = 0;
		virtual ~Coordinate();
};

template<uint32 N>
class CartesianCoordiante:
	public Coordinate<N>
{
	protected:
		const SingleQuantity _resolution;
	public:
		CartesianCoordiante(SingleQuantity resolution):
			_resolution(resolution)
		{
		}
		virtual PxPoint<N> toPixel(const QPoint<N>& point)
		{
			PxPoint<N> result;
			for (uint32 idim = 0; idim < N; ++idim)
			{
				for (uint32 iunit = 0; iunit < point[idim].getNumberOfUnits(); ++iunit)
				{
					const SingleQuantity& sq_point = point[idim].getSingleQuantity(iunit);
					const SingleQuantity& sq_result =sq_point/_resolution;
					if (sq_result.getUnit()==Unit("mm"))
					{
						result[idim]=sq_result.getValue();
					}
				}
			}
			return result;
		}
		virtual ~CartesianCoordiante()
		{

		}
};

template<uint32 N>
class Atlas
{
	protected:
		std::vector<Coordinate<N>*> _coordinates;
	public:
		Atlas(Coordinate<N>* basis);
		void addChart(const Coordinate<N>* coordiante);
		~Atlas();
};

}

#endif


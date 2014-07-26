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
class SPoint:
	public Point<SingleQuantity,N>
{
};

template<uint32 N>
class PxPoint:
	public Point<float32,N>
{
};

template<uint32 N>
class Coordinate
{
	public:
		virtual PxPoint<N> toPixel(const SPoint<N>& sqPoint) = 0;
};

template<uint32 N>
class CartesianCoordiante:
	public Coordinate<N>
{
	protected:
		SingleQuantity _resolution;
	public:
		CartesianCoordiante(SingleQuantity resolution):
			_resolution(resolution)
		{
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


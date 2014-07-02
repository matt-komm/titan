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


//this is not supported by < gcc4.7
template<uint32 N>
using QPoint = Point<Quantity,N>;
template<uint32 N>
using PxPoint = Point<float32,N>;

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
		Quantity _resolution;
	public:
		CartesianCoordiante(Quantity resolution):
			_resolution(resolution)
		{
			if (resolution.getNumberOfUnits()>1)
			{
				throw std::string("Cannot specify mixed quantity as resolution");
			}
		}
		virtual PxPoint<N> toPixel(const QPoint<N>& quantity)
		{
			PxPoint<N> result;
			for (uint32 idim = 0; idim < N; ++idim)
			{
				result[idim]=(quantity[idim]/_resolution.getUnit(0)).getValue(0);
			}
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


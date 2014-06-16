#ifndef __COORDINATE_H__
#define __COORDINATE_H__

#include "titan/core/Quantity.hpp"

#include <array>

namespace titan
{

template<class TYPE>
class Point
{
	protected:
		std::vector<const TYPE> _x;
	public:
		Point(const TYPE& x1)
		{
			_x.push_back(x1);
		}
		Point(const TYPE& x1, const TYPE& x2)
		{
			_x.push_back(x1);
			_x.push_back(x2);

		}
		Point(const TYPE& x1, const TYPE& x2, const TYPE& x3)
		{
			_x.push_back(x1);
			_x.push_back(x2);
			_x.push_back(x3);
		}
		const TYPE operator[](uint32 index) const
		{
			return _x[index];
		}
};

class Coordinate
{
	protected:
		const Unit _unit;
	public:
		Coordinate(const Unit& unit);
		virtual float32 toPixel(const Quantity& quantity) = 0;
		virtual ~Coordinate();
};

class CoordinateGrid
{
	protected:
		std::vector<Coordinate*> _coordinates;
	public:
		CoordinateGrid();
		void addCoordinate(const Coordinate& coordiante);

		~CoordinateGrid();
};

}

#endif


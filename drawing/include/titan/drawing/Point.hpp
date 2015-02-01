#ifndef __POINT_H__
#define __POINT_H__

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

		inline Point<TYPE,N>& operator+=(const Point<TYPE,N>& p)
        {
		    for (uint32 i = 0; i < N; ++i)
		    {
		        _x[i]+=p[i];
		    }
		    return *this;
        }

		inline Point<TYPE,N>& operator-=(const Point<TYPE,N>& p)
        {
            for (uint32 i = 0; i < N; ++i)
            {
                _x[i]-=p[i];
            }
            return *this;
        }

		inline Point<TYPE,N> operator+(const Point<TYPE,N>& p) const
        {
		    Point<TYPE,N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                //newPoint[i]=_x+p[i];
            }
            return std::move(newPoint);
        }

        inline Point<TYPE,N> operator-(const Point<TYPE,N>& p) const
        {
            Point<TYPE,N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                //newPoint[i]=_x-p[i];
            }
            return std::move(newPoint);
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
typedef SPoint<2> SPoint2d;

template<uint32 N>
class PxPoint:
	public Point<float32,N>
{
};
typedef PxPoint<2> PxPoint2d;


}

#endif


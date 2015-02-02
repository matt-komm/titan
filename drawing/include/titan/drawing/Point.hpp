#ifndef __POINT_H__
#define __POINT_H__

#include "titan/core/Quantity.hpp"
#include "titan/core/StreamInterface.hpp"

#include <array>
#include <initializer_list>
#include <sstream>

namespace titan
{

template<class TYPE, titan::uint32 N>
class Point:
    public StreamInterface
{
	protected:
		std::array<TYPE,N> _x;
	public:
		Point()
		{
		}

		Point(const Point& p):
		    _x(p._x)
		{
		}

		Point(Point&& p):
            _x(std::move(p._x))
        {
        }

		Point& operator=(const Point& p)
        {
		    for (uint32 i = 0; i < N; ++i)
		    {
		        _x[i]=p._x[i];
		    }
		    return *this;
        }

		Point& operator=(Point&& p)
        {
            _x=std::move(p._x);
        }

		template<typename... TT>
		Point(TT&&... x):
		    _x{{std::forward<TT>(x)...}}
		{
		}


		Point(const std::initializer_list<TYPE>& x)
        {
		    for (const TYPE* value = x.begin(); value != x.end(); ++value)
		    {
		        int i = value-x.begin();
		        _x[i]=*value;
		    }
        }

		template<typename... TT>
        inline Point& operator=(TT&&... x)
        {
		    _x={{std::forward<TT>(x)...}};
		    return *this;
        }

		Point& operator=(std::initializer_list<TYPE&&>&& x)
        {
            for (TYPE&& value = x.begin(); value != x.end(); ++value)
            {
                int i = value-x.begin();
                _x[i]=value;
            }
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
                newPoint[i]=_x+p[i];
            }
            return std::move(newPoint);
        }

        inline Point<TYPE,N> operator-(const Point<TYPE,N>& p) const
        {
            Point<TYPE,N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x-p[i];
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

		virtual std::string toString() const
		{
		    std::stringstream ss;
		    ss<<"[";
		    for (uint32 i=0; i<N-1; ++i)
		    {
		        ss<<"["<<_x[i]<<"],";
		    }
		    ss<<"["<<_x[N-1]<<"]";
		    ss<<"]";
		    return ss.str();
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


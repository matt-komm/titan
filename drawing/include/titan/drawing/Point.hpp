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

		Point(const Point<TYPE,N>& p):
		    _x(p._x)
		{
		}

		Point(Point<TYPE,N>&& p):
            _x(std::move(p._x))
        {
        }

		Point& operator=(const Point<TYPE,N>& p)
        {
		    for (uint32 i = 0; i < N; ++i)
		    {
		        _x[i]=p._x[i];
		    }
		    return *this;
        }

		Point& operator=(Point<TYPE,N>&& p)
        {
            _x=std::move(p._x);
            return *this;
        }

		Point(const std::initializer_list<TYPE>& x)
        {
		    for (const TYPE* value = x.begin(); value != x.end(); ++value)
		    {
		        int i = value-x.begin();
		        _x[i]=(*value);
		    }
        }

		Point& operator=(const std::initializer_list<TYPE>& x)
        {
            for (TYPE* value = x.begin(); value != x.end(); ++value)
            {
                int i = value-x.begin();
                _x[i]=(*value);
            }
        }

        template<class TT>
        Point<TYPE,N>& operator+=(const TT& t)
        {
            for (uint32 i = 0; i < N; ++i)
            {
                _x[i]+=t;
            }
            return *this;
        }

        template<class TT>
        Point<TYPE,N>& operator+=(const Point<TT,N>& t)
        {
            for (uint32 i = 0; i < N; ++i)
            {
               _x[i]+=t[i];
            }
            return *this;
        }

        template<class TT>
        auto operator-(const TT& t) const -> Point<decltype(_x[0] + t),N>
        {
            Point<decltype(_x[0] + t),N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x[i]+t;
            }
            return std::move(newPoint);
        }

        template<class TT>
        auto operator+(const Point<TT,N>& p) const -> Point<decltype(_x[0] + p[0]),N>
        {
            Point<decltype(_x[0] + p[0]),N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x[i]+p[i];
            }
            return std::move(newPoint);
        }


        template<class TT>
        Point<TYPE,N>& operator-=(const TT& t)
        {
            for (uint32 i = 0; i < N; ++i)
            {
                _x[i]-=t;
            }
            return *this;
        }

        template<class TT>
        Point<TYPE,N>& operator-=(const Point<TT,N>& t)
        {
            for (uint32 i = 0; i < N; ++i)
            {
               _x[i]-=t[i];
            }
            return *this;
        }

        template<class TT>
        auto operator-(const TT& t) const -> Point<decltype(_x[0] - t),N>
        {
            Point<decltype(_x[0] - t),N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x[i]-t;
            }
            return std::move(newPoint);
        }

        template<class TT>
        auto operator-(const Point<TT,N>& p) const -> Point<decltype(_x[0] - p[0]),N>
        {
            Point<decltype(_x[0] - p[0]),N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x[i]-p[i];
            }
            return std::move(newPoint);
        }

        template<class TT>
        Point<TYPE,N>& operator*=(const TT& t)
        {
            for (uint32 i = 0; i < N; ++i)
            {
                _x[i]*=t;
            }
            return *this;
        }

        template<class TT>
        Point<TYPE,N>& operator*=(const Point<TT,N>& t)
        {
            for (uint32 i = 0; i < N; ++i)
            {
               _x[i]*=t[i];
            }
            return *this;
        }

        template<class TT>
        auto operator*(const TT& t) const -> Point<decltype(_x[0] * t),N>
        {
            Point<decltype(_x[0] * t),N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x[i]*t;
            }
            return std::move(newPoint);
        }

        template<class TT>
        auto operator*(const Point<TT,N>& p) const -> Point<decltype(_x[0] * p[0]),N>
        {
            Point<decltype(_x[0] * p[0]),N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x[i]*p[i];
            }
            return std::move(newPoint);
        }

        template<class TT>
        Point<TYPE,N>& operator/=(const TT& t)
        {
            for (uint32 i = 0; i < N; ++i)
            {
                _x[i]/=t;
            }
            return *this;
        }

        template<class TT>
        Point<TYPE,N>& operator/=(const Point<TT,N>& t)
        {
            for (uint32 i = 0; i < N; ++i)
            {
               _x[i]/=t[i];
            }
            return *this;
        }

        template<class TT>
        auto operator/(const TT& t) const -> Point<decltype(_x[0] / t),N>
        {
            Point<decltype(_x[0] / t),N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x[i]/t;
            }
            return std::move(newPoint);
        }

        template<class TT>
        auto operator/(const Point<TT,N>& p) const -> Point<decltype(_x[0] / p[0]),N>
        {
            Point<decltype(_x[0] / p[0]),N> newPoint;
            for (uint32 i = 0; i < N; ++i)
            {
                newPoint[i]=_x[i]/p[i];
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


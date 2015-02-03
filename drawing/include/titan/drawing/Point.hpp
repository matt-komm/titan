#ifndef __POINT_H__
#define __POINT_H__

#include "titan/core/Quantity.hpp"
#include "titan/core/StreamInterface.hpp"

#include <vector>
#include <initializer_list>
#include <sstream>
#include <stdexcept>

namespace titan
{

template<class TYPE>
class Point:
    public StreamInterface
{
	protected:
		std::vector<TYPE> _x;
	public:
		Point(uint32 size=0):
		    _x(size)
		{
		}

		Point(const Point<TYPE>& p):
		    _x(p._x)
		{
		}

		Point(Point<TYPE>&& p):
            _x(std::move(p._x))
        {
        }

		inline uint32 size() const
		{
		    return _x.size();
		}

		Point<TYPE>& operator=(const Point<TYPE>& p)
        {
            _x.resize(p.size());
		    for (uint32 i = 0; i < _x.size(); ++i)
		    {
		        _x[i]=p._x[i];
		    }
		    return *this;
        }

		Point<TYPE>& operator=(Point<TYPE>&& p)
        {
            _x=std::move(p._x);
            return *this;
        }

		Point(const std::initializer_list<TYPE>& x):
		    _x(x.size())
        {
		    for (const TYPE* value = x.begin(); value != x.end(); ++value)
		    {
		        int i = value-x.begin();
		        _x[i]=(*value);
		    }
        }

		Point<TYPE>& operator=(const std::initializer_list<TYPE>& x)
        {
		    _x.resize(x.size());
            for (TYPE* value = x.begin(); value != x.end(); ++value)
            {
                int i = value-x.begin();
                _x[i]=(*value);
            }
            return *this;
        }

        template<class TT>
        Point<TYPE>& operator+=(const TT& t)
        {
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                _x[i]+=t;
            }
            return *this;
        }

        template<class TT>
        Point<TYPE>& operator+=(const Point<TT>& t)
        {
            for (uint32 i = 0; i < _x.size(); ++i)
            {
               _x[i]+=t[i];
            }
            return *this;
        }

        template<class TT>
        auto operator-(const TT& t) const -> Point<decltype(_x[0] + t)>
        {
            Point<decltype(_x[0] + t)> newPoint(_x.size());
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                newPoint[i]=_x[i]+t;
            }
            return std::move(newPoint);
        }

        template<class TT>
        auto operator+(const Point<TT>& p) const -> Point<decltype(_x[0] + p[0])>
        {
            if (_x.size()!=p.size())
            {
                throw std::runtime_error("Points to add differ in size");
            }
            Point<decltype(_x[0] + p[0])> newPoint(_x.size());
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                newPoint[i]=_x[i]+p[i];
            }
            return std::move(newPoint);
        }


        template<class TT>
        Point<TYPE>& operator-=(const TT& t)
        {
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                _x[i]-=t;
            }
            return *this;
        }

        template<class TT>
        Point<TYPE>& operator-=(const Point<TT>& t)
        {
            for (uint32 i = 0; i < _x.size(); ++i)
            {
               _x[i]-=t[i];
            }
            return *this;
        }

        template<class TT>
        auto operator-(const TT& t) const -> Point<decltype(_x[0] - t)>
        {
            Point<decltype(_x[0] - t)> newPoint(_x.size());
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                newPoint[i]=_x[i]-t;
            }
            return std::move(newPoint);
        }

        template<class TT>
        auto operator-(const Point<TT>& p) const -> Point<decltype(_x[0] - p[0])>
        {
            if (_x.size()!=p.size())
            {
                throw std::runtime_error("Points to subtract differ in size");
            }
            Point<decltype(_x[0] - p[0])> newPoint(_x.size());
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                newPoint[i]=_x[i]-p[i];
            }
            return std::move(newPoint);
        }

        template<class TT>
        Point<TYPE>& operator*=(const TT& t)
        {
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                _x[i]*=t;
            }
            return *this;
        }

        template<class TT>
        Point<TYPE>& operator*=(const Point<TT>& t)
        {
            for (uint32 i = 0; i < _x.size(); ++i)
            {
               _x[i]*=t[i];
            }
            return *this;
        }

        template<class TT>
        auto operator*(const TT& t) const -> Point<decltype(_x[0] * t)>
        {
            Point<decltype(_x[0] * t)> newPoint(_x.size());
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                newPoint[i]=_x[i]*t;
            }
            return std::move(newPoint);
        }

        template<class TT>
        auto operator*(const Point<TT>& p) const -> Point<decltype(_x[0] * p[0])>
        {
            if (_x.size()!=p.size())
            {
                throw std::runtime_error("Points to multiply differ in size");
            }
            Point<decltype(_x[0] * p[0])> newPoint(_x.size());

            for (uint32 i = 0; i < _x.size(); ++i)
            {
                newPoint[i]=_x[i]*p[i];
            }
            return std::move(newPoint);
        }

        template<class TT>
        Point<TYPE>& operator/=(const TT& t)
        {
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                _x[i]/=t;
            }
            return *this;
        }

        template<class TT>
        Point<TYPE>& operator/=(const Point<TT>& t)
        {
            for (uint32 i = 0; i < _x.size(); ++i)
            {
               _x[i]/=t[i];
            }
            return *this;
        }

        template<class TT>
        auto operator/(const TT& t) const -> Point<decltype(_x[0] / t)>
        {
            Point<decltype(_x[0] / t)> newPoint(_x.size());
            for (uint32 i = 0; i < _x.size(); ++i)
            {
                newPoint[i]=_x[i]/t;
            }
            return std::move(newPoint);
        }

        template<class TT>
        auto operator/(const Point<TT>& p) const -> Point<decltype(_x[0] / p[0])>
        {
            if (_x.size()!=p.size())
            {
                throw std::runtime_error("Points to divide differ in size");
            }
            Point<decltype(_x[0] / p[0])> newPoint(_x.size());
            for (uint32 i = 0; i < _x.size(); ++i)
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
		    for (uint32 i=0; i<_x.size()-1; ++i)
		    {
		        ss<<"["<<_x[i]<<"],";
		    }
		    ss<<"["<<_x[_x.size()-1]<<"]";
		    ss<<"]";
		    return ss.str();
		}
};

typedef Point<Quantity> QPoint;
typedef Point<float32> PxPoint;


}

#endif


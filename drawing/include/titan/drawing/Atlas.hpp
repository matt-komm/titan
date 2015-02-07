#ifndef __ATLAS_H__
#define __ATLAS_H__

#include "titan/core/Quantity.hpp"
#include "titan/drawing/Point.hpp"
#include "titan/drawing/CoordinateSystem.hpp"

#include <array>

namespace titan
{
/*
template<uint32 N>
class Atlas
{
    protected:
        std::map<std::string,const CoordinateSystem<N>*> _coordinates;
    public:
        Atlas()
        {
        }

        void addChart(const CoordinateSystem<N>* coordinate, const std::string& name)
        {
            if (_coordinates.find(name)!=_coordinates.end())
            {
                throw std::string("Coordinate system with unit '"+name+"' already exists in atlas");
            }
            else
            {
                _coordinates[name]=coordinate;
            }
        }

        ~Atlas()
        {
            for (std::pair<std::string,const CoordinateSystem<N>*> coord: _coordinates)
            {
                delete coord.second;
            }
            _coordinates.clear();
        }
};
typedef Atlas<2> Atlas2d;
*/

}

#endif


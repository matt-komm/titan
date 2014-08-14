#include "titan/drawing/Drawing.hpp"

#include <functional>
#include <algorithm>

namespace titan
{



Drawing::Drawing()
{
}

void Drawing::render()
{
	//1. sort for z-index
	std::sort(_drawTypes.begin(),_drawTypes.end(),std::less<DrawType*>());
	//(optional) layout
	//2. calculate biggest bounding box
	//3. book canvas
	//4. draw all
	//5. save

}

}

/*
Class::Class(const Class& c)
{
}

Class::Class(Class&& c)
{
}

Class& Class::operator=(const Class& c)
{
    return *this;
}

Class& Class::operator=(Class&& c)
{
    return *this;
}

Class::~Class()
{
}
*/


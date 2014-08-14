#ifndef __DRAWING_H__
#define __DRAWING_H__

#include "titan/drawing/DrawType.hpp"

#include <vector>

namespace titan
{

class Drawing
{
    protected:
		std::vector<DrawType*> _drawTypes;
    public:
		Drawing();

		void add(const DrawType& drawType);
		void render();
		/*
        Class(const Class& c);
        Class(Class&& c);
        Class& operator=(const Class& c);
        Class& operator=(Class&& c);
        ~Class();
        */
};

}

#endif


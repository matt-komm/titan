#ifndef __DRAWING_H__
#define __DRAWING_H__

#include <vector>

namespace titan
{

class DrawType;

class Drawing
{
    protected:
        std::vector<DrawType*> _drawTypes;
    public:
        Drawing();

        void add( DrawType* drawType);
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


#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "titan/drawing/Stroke.hpp"
#include "titan/drawing/Fill.hpp"

namespace titan
{

class Renderer
{
    protected:
    public:
        Renderer();
        ~Renderer();
        
        virtual void setStroke(const Stroke& stroke) = 0;
        virtual void setFill(const Fill& stroke) = 0;
        virtual void drawLine(double x1, double y1, double x2, double y2) = 0;
        virtual void drawRect(double x1, double y1, double x2, double y2) = 0;
        virtual void fillRect(double x1, double y1, double x2, double y2) = 0;
        virtual void drawEclipse(double midx, double midy, double r) = 0;
        virtual void fillEclipse(double midx, double midy, double r) = 0;
        virtual void drawCircle(double midx, double midy, double r) = 0;
        virtual void fillCircle(double midx, double midy, double r) = 0;
};

}

#endif


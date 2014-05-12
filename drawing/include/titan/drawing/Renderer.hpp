#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "titan/drawing/Stroke.hpp"
#include "titan/drawing/Fill.hpp"
#include "titan/drawing/Context.hpp"
#include "titan/drawing/Canvas.hpp"


namespace titan
{

class Renderer
{
    protected:
    public:
        Renderer();
        ~Renderer();
        
        virtual void setStroke(Context& context, const Stroke& stroke) const = 0;
        virtual void setFill(Context& context, const Fill& stroke) const = 0;
        virtual void drawLine(Context& context, double x1, double y1, double x2, double y2) const = 0;
        virtual void drawRect(Context& context, double x1, double y1, double x2, double y2) const = 0;
        virtual void fillRect(Context& context, double x1, double y1, double x2, double y2) const = 0;
        virtual void drawEclipse(Context& context, double midx, double midy, double r) const = 0;
        virtual void fillEclipse(Context& context, double midx, double midy, double r) const = 0;
        virtual void drawCircle(Context& context, double midx, double midy, double r) const = 0;
        virtual void fillCircle(Context& context, double midx, double midy, double r) const = 0;
        virtual Context& createContext(Canvas* canvas) const = 0;
};

}

#endif


#ifndef __CLASS_H__
#define __CLASS_H__

#include "titan/drawing/Renderer.hpp"
#include "titan/drawing/Context.hpp"
#include "titan/drawing/Canvas.hpp"

#include "CairoContext.hpp"
#include "CairoCanvas.hpp"

namespace titan
{
namespace plugins
{

class CairoRenderer:
	public Renderer
{
    protected:
    public:
		CairoRenderer();
        ~CairoRenderer();

        virtual void setStroke(Context& context, const Stroke& stroke) const;
		virtual void setFill(Context& context, const Fill& stroke) const;
		virtual void drawLine(Context& context, double x1, double y1, double x2, double y2) const;
		virtual void drawRect(Context& context, double x1, double y1, double x2, double y2) const;
		virtual void fillRect(Context& context, double x1, double y1, double x2, double y2) const;
		virtual void drawEclipse(Context& context, double midx, double midy, double r) const;
		virtual void fillEclipse(Context& context, double midx, double midy, double r) const;
		virtual void drawCircle(Context& context, double midx, double midy, double r) const;
		virtual void fillCircle(Context& context, double midx, double midy, double r) const;
		virtual Context& createContext(Canvas* canvas) const;

};

}
}

#endif


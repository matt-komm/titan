#ifndef __CairoContext_H__
#define __CairoContext_H__

#include "titan/drawing/ContextInterface.hpp"
#include "titan/core/Types.hpp"

#include "cairo.h"



namespace titan
{
namespace plugins
{

class CairoCanvas;

class CairoContext:
    public titan::ContextInterface
{
    protected:
        CairoCanvas& _cairoCanvas;
        cairo_t* _cairo_context;
        Stroke _currentStroke;
        Fill _currentFill;
        Font _currentFont;
        Color _currentColor;
        float32 _currentLineWidth;
    public:
        CairoContext(CairoCanvas& cairoCanvas);
        virtual ~CairoContext();

        virtual void setAntialising(Antialising::type antialising);
        virtual void setStroke(const Stroke& stroke);
        virtual void setFill(const Fill& stroke);
        virtual void setFont(const Font& font);
        virtual void drawText(uint32 x, uint32 y, const std::string& text);
        virtual void drawLine(uint32 x1, uint32 y1, uint32 x2, uint32 y2);
        virtual void drawRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2);
        virtual void fillRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2);



};

}
}

#endif


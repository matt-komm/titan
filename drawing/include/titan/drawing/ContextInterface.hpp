#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "titan/drawing/Stroke.hpp"
#include "titan/drawing/Fill.hpp"
#include "titan/drawing/Font.hpp"

#include "titan/core/Types.hpp"



namespace titan
{

class ContextInterface
{
    protected:
    public:
        virtual ~ContextInterface()
        {
        }
        virtual void setAntialising(Antialising::type antialising) = 0;
        virtual void setStroke(const Stroke& stroke) = 0;
        virtual void setFill(const Fill& stroke) = 0;
        virtual void setFont(const Font& font) = 0;
        virtual void drawText(uint32 x, uint32 y, const std::string& text) = 0;
        virtual void drawLine(uint32 x1, uint32 y1, uint32 x2, uint32 y2) = 0;
        virtual void drawRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2) = 0;
        virtual void fillRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2) = 0;
};

}

#endif



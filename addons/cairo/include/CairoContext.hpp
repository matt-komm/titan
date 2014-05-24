#ifndef __CairoContext_H__
#define __CairoContext_H__

#include "titan/drawing/Context.hpp"
#include "titan/core/Types.hpp"

#include "cairo.h"



namespace titan
{
namespace plugins
{

class CairoContext:
	public Context
{
    protected:
    public:
		CairoContext();
        ~CairoContext();

        virtual void setStroke(Stroke& stroke);
		virtual void setFill(Fill& stroke);
		virtual void drawLine(uint32 x1, uint32 y1, uint32 x2, uint32 y2);
		virtual void drawRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2);
		virtual void fillRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2);

};

}
}

#endif


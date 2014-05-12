#ifndef __CairoContext_H__
#define __CairoContext_H__

#include "titan/drawing/Context.hpp"

#include "cairo.h"

namespace titan
{
namespace plugins
{

class CairoContext:
	public Context
{
    protected:
		cairo_t* _context;
    public:
		CairoContext(cairo_t* context);
        ~CairoContext();
};

}
}

#endif


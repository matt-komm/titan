#include "CairoContext.hpp"

namespace titan
{
namespace plugins
{


CairoContext::CairoContext(cairo_t* context):
	titan::Context(),
	_context(context)
{
}

CairoContext::~CairoContext()
{
}

}
}

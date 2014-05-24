#include "CairoRenderer.hpp"

namespace titan
{
namespace plugins
{


CairoRenderer::CairoRenderer()
{
}

CairoRenderer::~CairoRenderer()
{
}


std::shared_ptr<Canvas> CairoRenderer::createCanvas(unsigned int pxWidth,unsigned int pxHeight, ColorType::type format) const
{
	return std::shared_ptr<Canvas>(new CairoCanvas(pxWidth,pxHeight,format));
}


}
}

#include "CairoCanvas.hpp"

#include <cairo.h>
#include <cairo-pdf.h>
#include <cairo-svg.h>
#include <iostream>

namespace titan
{
namespace plugins
{

CairoCanvas::CairoCanvas(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorType):
	CanvasInterface(pxWidth,pxHeight,outputName,outputType,colorType),
	_cairoContext(nullptr),
	_cairo_surface(nullptr)
{

	if (outputType==OutputType::PNG)
	{
		cairo_format_t format=CAIRO_FORMAT_ARGB32;
		if (colorType==ColorType::ARGB32)
		{
			format=CAIRO_FORMAT_ARGB32;
		}
		else if (colorType==ColorType::OUTPUTDEFAULT)
		{
			format=CAIRO_FORMAT_ARGB32;
		}
		else if (colorType==ColorType::RGB24)
		{
			format=CAIRO_FORMAT_RGB24;
		}
		_cairo_surface = cairo_image_surface_create(
			format,
			1.0*pxWidth,
			1.0*pxHeight
		);

	}
	else if (outputType==OutputType::PDF)
	{
		_cairo_surface = cairo_pdf_surface_create(outputName.c_str(),1.0*pxWidth,1.0*pxHeight);
	}
	else if (outputType==OutputType::SVG)
	{
		_cairo_surface = cairo_svg_surface_create(outputName.c_str(),1.0*pxWidth,1.0*pxHeight);
	}
	else
	{
		throw std::string("cannot create canvas with format");
	}
	if (!_cairo_surface)
	{
		throw std::string("no cairo surface created");
	}
	//std::cout<<cairo_status_to_string(cairo_surface_status (_cairo_surface))<<std::endl;
}

CairoCanvas::~CairoCanvas()
{
	delete _cairoContext;
	cairo_surface_destroy(_cairo_surface);
}

ContextInterface& CairoCanvas::getContext()
{
	if (!_cairoContext)
	{
		_cairoContext = new CairoContext(*this);
	}
	return *_cairoContext;
}

void CairoCanvas::freeSurface()
{
	if (this->getOutputType()==OutputType::PNG)
	{
		cairo_surface_write_to_png(_cairo_surface,this->getOutputName().c_str());
	}
	cairo_surface_finish(_cairo_surface);
	delete _cairoContext;
	cairo_surface_destroy(_cairo_surface);
}

}
}

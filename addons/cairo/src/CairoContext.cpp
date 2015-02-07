#include "CairoContext.hpp"
#include "CairoCanvas.hpp"

#include <iostream>

namespace titan
{
namespace plugins
{


CairoContext::CairoContext(CairoCanvas& cairoCanvas):
    _cairoCanvas(cairoCanvas),
    _currentColor(Color::argb32())
{
    _cairo_context=cairo_create(_cairoCanvas.getCairoSurface());
}

CairoContext::~CairoContext()
{
    cairo_destroy(_cairo_context);
}

void CairoContext::setStroke(const Stroke& stroke)
{
    _currentStroke=stroke;
}

void CairoContext::setFill(const Fill& fill)
{
    _currentFill=fill;
}

void CairoContext::setAntialising(Antialising::type antialising)
{
    switch(antialising)
    {
        case Antialising::NONE:
            cairo_set_antialias(_cairo_context,CAIRO_ANTIALIAS_NONE);
            break;
        case Antialising::DEFAULT:
            cairo_set_antialias(_cairo_context,CAIRO_ANTIALIAS_DEFAULT);
            break;
        case Antialising::SIMPLE:
            cairo_set_antialias(_cairo_context,CAIRO_ANTIALIAS_GRAY);
            break;
        case Antialising::BEST:
            cairo_set_antialias(_cairo_context,CAIRO_ANTIALIAS_SUBPIXEL);
            break;
    }
}

void CairoContext::setFont(const Font& font)
{
    _currentFont=font;
}

void CairoContext::drawText(uint32 x, uint32 y, const std::string& text)
{
    const Color& color = _currentFont.getColor();
    if (_currentColor!=color)
    {
        cairo_set_source_rgba(_cairo_context,color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
        _currentColor=color;
    }
    cairo_font_slant_t slant = CAIRO_FONT_SLANT_NORMAL;
    cairo_font_weight_t weight = CAIRO_FONT_WEIGHT_NORMAL;
    if (_currentFont.getFontStyle()==FontStyle::ITALIC)
    {
        slant = CAIRO_FONT_SLANT_ITALIC;
    }
    else if (_currentFont.getFontStyle()==FontStyle::BOLD)
    {
        weight = CAIRO_FONT_WEIGHT_BOLD;
    }
    else if (_currentFont.getFontStyle()==FontStyle::BOLDITALIC)
    {
        slant = CAIRO_FONT_SLANT_ITALIC;
        weight = CAIRO_FONT_WEIGHT_BOLD;
    }
    cairo_select_font_face (_cairo_context, _currentFont.getFontName().c_str(), slant, weight);
    cairo_set_font_size (_cairo_context, _currentFont.getFontSize());
    cairo_move_to (_cairo_context, x, y);
    cairo_show_text (_cairo_context, text.c_str());
}

void CairoContext::drawLine(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{
    const Color& color = _currentStroke.getColor();
    if (_currentColor!=color)
    {
        cairo_set_source_rgba(_cairo_context,color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
        _currentColor=color;
    }
    if (_currentLineWidth!=_currentStroke.getWidth())
    {
        cairo_set_line_width(_cairo_context,_currentStroke.getWidth());
        _currentLineWidth=_currentStroke.getWidth();
    }
    cairo_move_to(_cairo_context,x1,y1);
    cairo_line_to(_cairo_context,x2,y2);
    cairo_stroke(_cairo_context);
}
void CairoContext::drawRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{
    const Color& color = _currentStroke.getColor();
    if (_currentColor!=color)
    {
        cairo_set_source_rgba(_cairo_context,color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
        _currentColor=color;
    }
    if (_currentLineWidth!=_currentStroke.getWidth())
    {
        cairo_set_line_width(_cairo_context,_currentStroke.getWidth());
        _currentLineWidth=_currentStroke.getWidth();
    }
    cairo_rectangle(_cairo_context,x1,y1,x2-x1,y2-y1);
    cairo_stroke(_cairo_context);
}

void CairoContext::fillRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{
    const Color& color = _currentFill.getColor();
    if (_currentColor!=color)
    {
        cairo_set_source_rgba(_cairo_context,color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
        _currentColor=color;
    }
    cairo_rectangle(_cairo_context,x1,y1,x2-x1,y2-y1);
    cairo_fill(_cairo_context);
}



}
}

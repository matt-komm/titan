#include "titan/core.hpp"
#include "titan/drawing.hpp"

#include <iostream>

using namespace titan;

int main()
{
    try
    {
        PluginFactory::getInstance()->loadPluginsFromFile("./libtitan-cairoplugin.so");
        Plugin<DrawingBackendInterface>* p = PluginFactory::getInstance()->getPlugin<DrawingBackendInterface>("CairoDrawingBackend");
        DrawingBackendInterface* cairoBackend = p->create();
        CanvasInterface* cv = cairoBackend->create(200,200,"test.svg",titan::OutputType::SVG);
        ContextInterface& context = cv->getContext();
        context.setStroke(Stroke::byColor(Color::argb32(0.5,0.0,0.0,0.0)));
        context.setFill(Fill::byColor(Color::argb32(1.0,0.1,0.2,0.6)));
        context.fillRect(20,20,180,180);
        context.setFill(Fill::byColor(Color::argb32(0.5,1.0,1.0,1.0)));
        context.fillRect(40,40,160,160);
        context.setAntialising(titan::Antialising::NONE);
        context.drawLine(0,0,200,200);
        context.drawRect(50,50,150,150);
        context.setFont(Font::byName("Courier",50.0,Color::argb32(0.5,1.0,0.0,0.0),FontStyle::BOLDITALIC));
        context.drawText(60,60,"bla");
        cv->freeSurface();

    } catch (std::string s)
    {
        std::cout<<s.c_str()<<std::endl;
    }

    return 0;

}

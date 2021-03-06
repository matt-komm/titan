#include "titan/core/LibraryLoader.hpp"
#include "titan/drawing/DrawingBackendInterface.hpp"
#include "CairoCanvas.hpp"

namespace titan
{
namespace plugins
{

class CairoDrawingBackend:
    public titan::DrawingBackendInterface
{
    protected:
    public:
        virtual CanvasInterface* create(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorType=ColorType::OUTPUTDEFAULT)
        {
            return new CairoCanvas(pxWidth,pxHeight,outputName,outputType,colorType);
        }
};

INIT(
    REGISTER_PLUGIN(DrawingBackendInterface,CairoDrawingBackend)
)


}
}

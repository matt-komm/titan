#include "titan/drawing/Canvas.hpp"

namespace titan
{

CanvasInterface::CanvasInterface(
	uint32 pxWidth,
	uint32 pxHeight,
	const std::string& outputName,
	OutputType::type outputType,
	ColorType::type colorType
	):
    _pxWidth(pxWidth),
    _pxHeight(pxHeight),
    _outputName(outputName),
    _outputType(outputType),
	_colorType(colorType)
{
}

CanvasInterface::~CanvasInterface()
{
}

}

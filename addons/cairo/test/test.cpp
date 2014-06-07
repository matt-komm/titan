#include "titan/core.hpp"
#include "titan/drawing.hpp"

#include "CairoCanvas.hpp"
#include "CairoContext.hpp"

using namespace titan;

int main()
{
	Canvas* cv = new plugins::CairoCanvas(200,200,titan::ColorType::ARGB32);
	Context& context = cv->getContext();
	context.drawLine(20,20,180,180);
	return 0;
}


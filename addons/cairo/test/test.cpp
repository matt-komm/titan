#include "titan/core.hpp"
#include "titan/drawing.hpp"

#include "CairoCanvas.hpp"
#include "CairoContext.hpp"

using namespace titan;

int main()
{
	Canvas* cv = new plugins::CairoCanvas(200,200,titan::ColorType::ARGB32);
	Context& context = cv->getContext();
	context.setStroke(Stroke::byColor(Color::argb32(1.0,0.1,0.2,0.6)));

	context.setFill(Fill::byColor(Color::argb32(1.0,0.1,0.2,0.6)));
	context.fillRect(20,20,180,180);
	context.setFill(Fill::byColor(Color::argb32(0.5,1.0,1.0,1.0)));
	context.fillRect(40,40,160,160);
	//context.drawLine(20,20,180,180);
	cv->save("test.png",OutputFormat::PNG);
	return 0;
}


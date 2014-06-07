#include "titan/core.hpp"
#include "titan/drawing.hpp"

#include "CairoCanvas.hpp"
#include "CairoContext.hpp"

using namespace titan;

int main()
{
	Canvas* cv = new plugins::CairoCanvas(200,200,titan::ColorType::ARGB32);
	Context& context = cv->getContext();
	context.fillRect(20,20,180,180);
	cv->save("test.png",OutputFormat::PNG);
	return 0;
}


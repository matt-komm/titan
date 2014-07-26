#include "titan/core.hpp"
#include "titan/drawing.hpp"

#include "gtest/gtest.h"

#include <iostream>

TEST(Drawing, CartesianCoordiante)
{
	using namespace titan;
	CartesianCoordiante2d  coords(0.1*mm/px);
	SPoint2d qpoint;
	qpoint[0]=1.0*cm;
	qpoint[1]=4.0*cm;
	PxPoint2d pxpoint = coords.toPixel(qpoint);
	EXPECT_FLOAT_EQ(pxpoint[0],100.0);
	EXPECT_FLOAT_EQ(pxpoint[1],400.0);
}

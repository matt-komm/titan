#include "titan/core.hpp"
#include "titan/drawing.hpp"

#include "gtest/gtest.h"

#include <iostream>


TEST(Drawing, Point)
{
    using namespace titan;
    Point<Quantity,2> p1(1*px,4*px);
    std::cout<<p1<<std::endl;
    /*
    Point<TESTTYPE,2> p2;
    p2[0]=1*cm;
    p2[1]=4*cm;
    Point<TESTTYPE,2> p3{{-4*cm, 2*cm}};
    p2+=p1;
    Point<TESTTYPE,2> p4 = {1*cm,4*cm};
    p3-=p1;
    Point<TESTTYPE,2> p5 = (1*cm,4*cm);
    */
}

TEST(Drawing, CartesianCoordiantes)
{
	using namespace titan;
	CartesianCoordinates2d  coords(0.1*mm/px);
	SPoint2d qpoint;
	qpoint[0]=1.0*cm;
	qpoint[1]=4.0*cm;
	PxPoint2d pxpoint = coords.toPixel(qpoint);
	EXPECT_FLOAT_EQ(pxpoint[0],100.0);
	EXPECT_FLOAT_EQ(pxpoint[1],400.0);
}

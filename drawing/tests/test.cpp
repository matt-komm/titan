#include "titan/core.hpp"
#include "titan/drawing.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <array>

TEST(Drawing, Point)
{
    using namespace titan;
    Point<float32,2> pFloats{{0.5,3.0}};
    Point<Unit,2> pUnits{{Unit("px"),Unit("px",2)}};
    Point<SingleQuantity,2> pSQ{{1*px,4*px}};
    Point<Quantity,2> pQ{{1*px+4*mm,4*px-2*mm}};


    Point<SingleQuantity,2> cpSQ = pFloats*pUnits;
    std::cout<<cpSQ<<std::endl;
    std::cout<<pQ+cpSQ<<std::endl;

    //std::array<Quantity,2> test{;
    //p1=p2-p1;

    /*

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

#include "titan/core.hpp"
#include "titan/drawing.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <initializer_list>

template<class PT>
void compare(const titan::Point<PT>& point, std::initializer_list<PT> args)
{
    for (const PT* arg = args.begin(); arg !=args.end(); ++arg)
    {
        EXPECT_EQ(point[arg-args.begin()],*arg);
    }
}

template<>
void compare(const titan::Point<titan::float32>& point, std::initializer_list<titan::float32> args)
{
    for (const titan::float32* arg = args.begin(); arg !=args.end(); ++arg)
    {
        EXPECT_FLOAT_EQ(point[arg-args.begin()],*arg);
    }
}

template<>
void compare(const titan::Point<titan::float64>& point, std::initializer_list<titan::float64> args)
{
    for (const titan::float64* arg = args.begin(); arg !=args.end(); ++arg)
    {
        EXPECT_DOUBLE_EQ(point[arg-args.begin()],*arg);
    }
}

TEST(Drawing, Point)
{
    using namespace titan;
    Point<float32> pFloats{{0.5,3.0}};
    Point<float64> pDoubles{{0.5,3.0}};
    Point<Unit> pUnits={{Unit("px"),Unit("px",2)}};
    Point<SingleQuantity> pSQ{{1*px,4*px}};
    Point<Quantity> pQ{{1*px+4*mm,4*px-2*mm}};

    compare(pFloats,{0.5f,3.0f});
    compare(pDoubles,{0.5,3.0});
    compare(pUnits,{Unit("px"),Unit("px",2)});
    compare(pSQ,{1*px,4*px});
    compare(pQ,{1*px+4*mm,4*px-2*mm});
    
    //std::cout<<pFloats+pFloats<<std::endl;

    Point<SingleQuantity> cpSQ = pFloats*pUnits;
    //std::cout<<cpSQ<<std::
    //std::cout<<pQ+cpSQ<<std::endl;

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

    CartesianCoordinates2d  coordsMM({0.1*mm,0.1*mm},{0*mm,0*mm});
    CartesianCoordinates2d  coordsPX({0.1*px,0.1*px},{0*px,0*px});

    QPoint qpoint(2);
    qpoint[0]=1.0*mm;
    qpoint[1]=4.0*mm+0.5*px;

    QPoint qpointConv = coordsMM.convert(qpoint);
    qpointConv+=coordsPX.convert(qpoint);
    std::cout<<qpointConv<<std::endl;
    //compare<Quantity>(qpointConv,{5.0,5.0});
}

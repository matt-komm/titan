#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>



TEST(Core, Unit)
{
	using namespace titan;
    Unit q1("mm");
    Unit q2("mm");
    Unit q3("mm",2);
    EXPECT_EQ(q1,q2);
    EXPECT_EQ(q1*q2,q3);
    EXPECT_EQ((q1*q2).getPower("mm"),2);
    EXPECT_EQ((q1*q3).getPower("mm"),3);
    EXPECT_EQ((q1/q3).getPower("mm"),-1);
    EXPECT_EQ((q1/q2).getPower("mm"),0);
    EXPECT_EQ((q1/q2).isScalar(),true);
    q3*=q1;
    EXPECT_EQ(q3.getPower("mm"),3);
    EXPECT_EQ(q1.getPower("mm"),1);
    q2/=q3;
    EXPECT_EQ(q2.getPower("mm"),-2);
	EXPECT_EQ(q3.getPower("mm"),3);
}


TEST(Core, Quantity)
{
	using namespace titan;
	SingleQuantity sq1(4324.53,Unit("mm"));
	SingleQuantity sq2(4324.53,Unit("px"));
	Quantity q = sq1+sq2;
	EXPECT_EQ(q.getNumberOfSingleQuantities(),(unsigned int)2);
	if (q.getSingleQuantity(0).getUnit()==sq1.getUnit())
	{
		EXPECT_FLOAT_EQ(q.getSingleQuantity(0).getValue(),sq1.getValue());
		EXPECT_EQ(q.getSingleQuantity(1).getUnit(),sq2.getUnit());
		EXPECT_FLOAT_EQ(q.getSingleQuantity(1).getValue(),sq2.getValue());
	}
	else
	{
		EXPECT_FLOAT_EQ(q.getSingleQuantity(0).getValue(),sq2.getValue());
		EXPECT_EQ(q.getSingleQuantity(1).getUnit(),sq1.getUnit());
		EXPECT_FLOAT_EQ(q.getSingleQuantity(1).getValue(),sq1.getValue());
	}

}

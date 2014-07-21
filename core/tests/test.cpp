#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>

using namespace titan;

TEST(Core, Unit)
{
    Unit q1("mm");
    Unit q2("mm");
    Unit q3("mm",2);
    EXPECT_EQ(q1,q2);
    EXPECT_EQ(q1*q2,q3);
    EXPECT_EQ((q1*q2).getPower("mm"),2);
    EXPECT_EQ((q1/q3).getPower("mm"),-1);
    EXPECT_EQ((q1/q2).getPower("mm"),0);
    //EXPECT_EQ((q1/q2).isScalar(),true);
}


TEST(Core, Quantity)
{
	Quantity q = 4324.53*mm+964.34*px;
	EXPECT_EQ(q.getNumberOfSingleQuantities(),(unsigned int)2);
	if (q.getSingleQuantity(0).getUnit()==Unit("mm"))
	{
		EXPECT_FLOAT_EQ(q.getSingleQuantity(0).getValue(),4324.53);
		EXPECT_EQ(q.getSingleQuantity(1).getUnit(),Unit("px"));
		EXPECT_FLOAT_EQ(q.getSingleQuantity(1).getValue(),964.34);
	}
	else
	{
		EXPECT_FLOAT_EQ(q.getSingleQuantity(0).getValue(),9564.34);
		EXPECT_EQ(q.getSingleQuantity(1).getUnit(),Unit("mm"));
		EXPECT_FLOAT_EQ(q.getSingleQuantity(1).getValue(),4324.53);
	}

}

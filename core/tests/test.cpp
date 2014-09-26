#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>
#include <string>



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

TEST(Core, GenericType)
{
	using namespace titan;
	GenericType strType = GenericType::fromValue<std::string>("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ`1234567890-=[]\\;',./~!@#$%^&*()_+{}|:\"<>? ");
	EXPECT_STREQ(strType.toString().c_str(),"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ`1234567890-=[]\\;',./~!@#$%^&*()_+{}|:\"<>? ");
	GenericType intType = GenericType::fromValue<int32>(1234567890);
	EXPECT_STREQ(intType.toString().c_str(),"1234567890");
	EXPECT_EQ(std::stoi(intType.toString()),1234567890);
	GenericType floatType = GenericType::fromValue<float32>(1234567890);
	EXPECT_FLOAT_EQ(std::stof(floatType.toString()),1234567890);

	EXPECT_THROW(GenericType::fromBoolString("bal"),std::string);
	EXPECT_THROW(GenericType::fromInt32String("bal"),std::string);
	EXPECT_THROW(GenericType::fromUInt32String("bal"),std::string);
	EXPECT_THROW(GenericType::fromFloat32String("bal"),std::string);
	EXPECT_THROW(GenericType::fromFloat64String("bal"),std::string);

}

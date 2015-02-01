#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <set>



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

void testQuantity(const titan::Quantity& quantity, std::vector<titan::SingleQuantity> singles)
{
    using namespace titan;
    std::set<Unit,Unit::less> nUnits;
    for (uint32 iquantity = 0; iquantity < quantity.getNumberOfSingleQuantities(); ++iquantity)
    {
        const SingleQuantity& sq = quantity.getSingleQuantity(iquantity);
        nUnits.insert(sq.getUnit());
    }
    EXPECT_EQ(nUnits.size(),singles.size());
    for (uint32 isingle = 0; isingle < singles.size(); ++isingle)
    {
        bool found = false;
        float32 totalValue = 0.0;

        for (uint32 iquantity = 0; iquantity < quantity.getNumberOfSingleQuantities(); ++iquantity)
        {
            const SingleQuantity& sq = quantity.getSingleQuantity(iquantity);
            if (sq.getUnit()==singles[isingle].getUnit())
            {
                totalValue+=sq.getValue();
                found=true;
            }
        }
        EXPECT_EQ(found,true);
        EXPECT_FLOAT_EQ(totalValue,singles[isingle].getValue());
    }
}

TEST(Core, Quantity)
{
	using namespace titan;
	SingleQuantity sq1(44.53,Unit("mm"));
	SingleQuantity sq2(4324.53,Unit("px"));

	Quantity q1 = sq1+sq2+sq2;
	q1.shrink();
	testQuantity(q1,{sq1,2*sq2});

	q1 += sq1;
	q1.shrink();
    testQuantity(q1,{sq1*2,2*sq2});

    q1 -= sq2;
    q1.shrink();
    testQuantity(q1,{sq1*2,sq2});

    q1 -= q1;
    q1.shrink();
    testQuantity(q1,{});

    Quantity q3 = q1-q1;
    q3.shrink();
    std::cout<<q3.toString()<<std::endl;
    testQuantity(q3,{});

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

	EXPECT_EQ(GenericType::fromString("bla"),GenericType::fromValue<std::string>("bla"));
	EXPECT_EQ(GenericType::fromBoolString("true"),GenericType::fromValue<bool>(true));
	EXPECT_EQ(GenericType::fromInt32String("12345"),GenericType::fromValue<int32>(12345));
	EXPECT_EQ(GenericType::fromUInt32String("12345"),GenericType::fromValue<uint32>(12345));
	EXPECT_EQ(GenericType::fromFloat32String("123.45"),GenericType::fromValue<float32>(123.45));
	EXPECT_EQ(GenericType::fromFloat64String("123.45"),GenericType::fromValue<float64>(123.45));

	EXPECT_NE(GenericType::fromString("bla"),GenericType::fromValue<std::string>("blub"));
	EXPECT_NE(GenericType::fromBoolString("true"),GenericType::fromValue<int32>(0));
	EXPECT_NE(GenericType::fromValue<bool>(true),GenericType::fromValue<bool>(false));
	EXPECT_NE(GenericType::fromValue<int32>(2),GenericType::fromValue<int32>(0));
	EXPECT_NE(GenericType::fromValue<uint32>(0),GenericType::fromValue<int32>(0));
	EXPECT_NE(GenericType::fromValue<float32>(0),GenericType::fromValue<int32>(0));
	EXPECT_NE(GenericType::fromValue<float64>(0),GenericType::fromValue<int32>(0));
}

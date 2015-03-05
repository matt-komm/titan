#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <set>



TEST(GenericType, string_casts)
{
    using namespace titan;
    GenericType strType = GenericType::fromValue<std::string>("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ`1234567890-=[]\\;',./~!@#$%^&*()_+{}|:\"<>? ");
    EXPECT_STREQ(strType.toString().c_str(),"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ`1234567890-=[]\\;',./~!@#$%^&*()_+{}|:\"<>? ");
    GenericType intType = GenericType::fromValue<int32>(1234567890);
    EXPECT_STREQ(intType.toString().c_str(),"1234567890");
    EXPECT_EQ(std::stoi(intType.toString()),1234567890);
    GenericType floatType = GenericType::fromValue<float32>(1234567890);
    EXPECT_FLOAT_EQ(std::stof(floatType.toString()),1234567890);
}

TEST(GenericType, exceptions)
{
    using namespace titan;
    EXPECT_THROW(GenericType::fromBoolString("bla"),titan::Exception);
    EXPECT_THROW(GenericType::fromInt32String("bla"),titan::Exception);
    EXPECT_THROW(GenericType::fromUInt32String("bla"),titan::Exception);
    EXPECT_THROW(GenericType::fromFloat32String("bla"),titan::Exception);
    EXPECT_THROW(GenericType::fromFloat64String("bla"),titan::Exception);
}

TEST(GenericType, type_casts)
{
    using namespace titan;
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



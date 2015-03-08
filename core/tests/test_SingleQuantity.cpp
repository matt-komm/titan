#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <set>


TEST(SingleQuantity,constructors)
{
    using namespace titan;
    Unit unit("mm");
    float32 value = 10.0;
    SingleQuantity sq1(value,unit);
    EXPECT_EQ(sq1.getUnit(),Unit("mm"));
    EXPECT_FLOAT_EQ(sq1.getValue(),10.0);
    value = 20.0;
    unit = Unit("blub");
    EXPECT_EQ(sq1.getUnit(),Unit("mm"));
    EXPECT_FLOAT_EQ(sq1.getValue(),10.0);
    EXPECT_EQ(sq1,SingleQuantity(10.0,Unit("mm")));
    EXPECT_NE(sq1,SingleQuantity(11.0,Unit("mm")));
    EXPECT_NE(sq1,SingleQuantity(10.0,Unit("px")));

    unit = Unit("mm");
    value = 10.0;
    SingleQuantity sq2=value*unit;
    EXPECT_EQ(sq2.getUnit(),Unit("mm"));
    EXPECT_FLOAT_EQ(sq2.getValue(),10.0);
    value = 20.0;
    unit = Unit("blub");
    EXPECT_EQ(sq2.getUnit(),Unit("mm"));
    EXPECT_FLOAT_EQ(sq2.getValue(),10.0);
    EXPECT_EQ(sq2,SingleQuantity(10.0,Unit("mm")));
    EXPECT_NE(sq2,SingleQuantity(11.0,Unit("mm")));
    EXPECT_NE(sq2,SingleQuantity(10.0,Unit("px")));

    SingleQuantity sq3(sq2);
    EXPECT_EQ(sq3.getUnit(),Unit("mm"));
    EXPECT_FLOAT_EQ(sq3.getValue(),10.0);
    value = 20.0;
    unit = Unit("blub");
    EXPECT_EQ(sq3.getUnit(),Unit("mm"));
    EXPECT_FLOAT_EQ(sq3.getValue(),10.0);
    EXPECT_EQ(sq3,SingleQuantity(10.0,Unit("mm")));
    EXPECT_NE(sq3,SingleQuantity(11.0,Unit("mm")));
    EXPECT_NE(sq3,SingleQuantity(10.0,Unit("px")));

    SingleQuantity sq4(std::move(sq3));
    EXPECT_EQ(sq4.getUnit(),Unit("mm"));
    EXPECT_FLOAT_EQ(sq4.getValue(),10.0);
}


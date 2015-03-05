#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <set>



TEST(Unit, comparisons)
{
    using namespace titan;
    Unit q1("mm");
    Unit q2("mm");
    Unit q3("mm",2);
    Unit q4("cm",1);
    EXPECT_EQ(q1,q1);
    EXPECT_EQ(q1,q2);
    EXPECT_NE(q1,q3);
}

TEST(Unit, getPower)
{
    using namespace titan;
    Unit q1("mm");
    Unit q2("mm");
    Unit q3("mm",2);
    Unit q4("cm",1);

    EXPECT_EQ(q1.getPower("mm"),1);
    EXPECT_EQ(q1.getPower("cm"),0);
    EXPECT_EQ(q1.getPower("m"),0);
    EXPECT_EQ(q1.getPower(""),0);
}


TEST(Unit, calculations)
{
    using namespace titan;
    Unit q1("mm");
    Unit q2("mm");
    Unit q3("mm",2);
    Unit q4("cm",1);
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

TEST(Unit, constructors)
{
    using namespace titan;
    Unit q1("mm");
    Unit q2("mm");
    Unit q3("mm",2);
    Unit q4("cm",1);

    Unit q5(q1);
    EXPECT_EQ(q5,q1);
    q1*=q2;
    EXPECT_NE(q5,q1);

    Unit q6(std::move(q2));
    EXPECT_EQ(q6.getPower("mm"),1);
    EXPECT_EQ(q6,Unit("mm",1));
    EXPECT_EQ(q2.getPower("mm"),0);
    EXPECT_EQ(q2,Unit());
}

TEST(Unit, assignments)
{
    using namespace titan;
    Unit q1("mm");
    Unit q2("mm");
    Unit q3("mm",2);
    Unit q4("cm",1);

    Unit q5=q1;
    EXPECT_EQ(q5,q1);
    q1*=q2;
    EXPECT_NE(q5,q1);

    Unit q6=std::move(q2);
    EXPECT_EQ(q6.getPower("mm"),1);
    EXPECT_EQ(q6,Unit("mm",1));
    EXPECT_EQ(q2.getPower("mm"),0);
    EXPECT_EQ(q2,Unit());
}

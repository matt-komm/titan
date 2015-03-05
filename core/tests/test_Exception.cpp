#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <set>

void testException(titan::uint32& lno)
{
    lno=__LINE__; titan_throw("TestException","test exception message",12345);
}

TEST(Core, Exception)
{
    titan::uint32 lno=0;
    EXPECT_THROW(testException(lno),titan::Exception);
    try
    {
        testException(lno);
    }
    catch (titan::Exception e)
    {
        EXPECT_EQ(e.type(),"TestException");
        EXPECT_EQ(e.file(),__FILE__);
        EXPECT_EQ(e.function(),"testException");
        EXPECT_EQ(e.lno(),lno);
        EXPECT_EQ(e.msg(),"test exception message12345");
    }

}

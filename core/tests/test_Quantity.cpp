#include "titan/core.hpp"

#include "gtest/gtest.h"

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <set>



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
    Quantity q2 = sq1-sq2;
    Quantity q3 = q1+q2;
    Quantity q4 = q1-q2;

    Quantity q5 = q3*3;
    //std::cout<<q3.getHash()<<std::endl;
    //std::cout<<q5.getHash()<<std::endl;
    Quantity q6 = q3/2.0;

    Quantity q7 = q3*sq1;
    Quantity q8 = q3/sq1;

    {
        SCOPED_TRACE("add SQ by copy");
        testQuantity(q1,{sq1,2*sq2});
    }
    q1 += sq1;
    {
        SCOPED_TRACE("add SQ by ref");
        testQuantity(q1,{sq1*2,2*sq2});
    }
    q1 -= sq2;
    {
        SCOPED_TRACE("sub SQ by ref");
        testQuantity(q1,{sq1*2,sq2});
    }

    q1 -= q1;
    {
        SCOPED_TRACE("sub to empty");
        testQuantity(q1,{});
    }

    {
        SCOPED_TRACE("add Q by copy");
        testQuantity(q3,{2*sq1,sq2});
    }

}

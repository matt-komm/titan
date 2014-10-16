#include "gtest/gtest.h"

#include "titan/core.hpp"
#include "titan/data.hpp"

TEST(Data, Accessor)
{
	using namespace titan;
	DynamicArray dynarray(new SwapAccessor());
}

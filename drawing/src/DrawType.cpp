#include "titan/drawing/DrawType.hpp"

namespace titan
{

bool DrawType::less::operator()(const titan::DrawType* dt1, const titan::DrawType* dt2) const
{
	return	dt1->getZIndex()<dt2->getZIndex();
}

}

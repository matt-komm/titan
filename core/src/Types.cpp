#include "titan/core/Types.hpp"



namespace titan
{

template<>
std::string TypeTmpl<std::string>::toString(std::ios_base::fmtflags mask) const
{
	return *_value;
}

}

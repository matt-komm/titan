#include "titan/core/Types.hpp"



namespace titan
{

//TODO: get spezialization working!

template<>
std::string TypeTmpl<std::string>::toString(std::ios_base::fmtflags mask) const
{
	return *_value;
}

}

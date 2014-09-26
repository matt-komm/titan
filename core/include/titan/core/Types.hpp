#ifndef __TYPES_H__
#define __TYPES_H__

#include <inttypes.h>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

namespace titan
{

typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;

typedef float float32;
typedef double float64;
typedef long double float128;


static_assert(sizeof(int8)==1, "int8 is not of required size: 1");
static_assert(sizeof(uint8)==1, "uint8 is not of required size: 1");
static_assert(sizeof(int16)==2, "int16 is not of required size: 2");
static_assert(sizeof(uint16)==2, "uint16 is not of required size: 2");
static_assert(sizeof(int32)==4, "int32 is not of required size: 4");
static_assert(sizeof(uint32)==4, "uint32 is not of required size: 4");
static_assert(sizeof(int64)==8, "int64 is not of required size: 8");
static_assert(sizeof(uint64)==8, "uint64 is not of required size: 8");

static_assert(sizeof(float32)==4, "float32 is not of required size: 4");
static_assert(sizeof(float64)==8, "float64 is not of required size: 8");
static_assert(sizeof(float128)==16, "float128 is not of required size: 16");


//TODO: use enum class here
struct ColorType
{
	enum type {ARGB32,RGB24,OUTPUTDEFAULT};
};

struct OutputType
{
	enum type {SVG,PNG,PDF};
};

struct Antialising
{
	enum type {NONE,DEFAULT,SIMPLE,BEST};
};

//TODO: use bitmask
struct FontStyle
{
	enum type {NORMAL,BOLD,ITALIC,BOLDITALIC};
};

class Type
{
	public:
		virtual Type* clone() const = 0;
		virtual std::string toString(std::ios_base::fmtflags mask = std::ios_base::boolalpha | std::ios_base::dec | std::ios_base::scientific) const = 0;
		virtual ~Type()
		{
		}
};

template<class TYPE>
class TypeTmpl:
	public Type
{
	private:
		TYPE* _value;
	public:
		TypeTmpl(TYPE value):
			_value(new TYPE(value))
		{
		}

		virtual Type* clone() const
		{
			return new TypeTmpl<TYPE>(*_value);
		}

		virtual std::string toString(std::ios_base::fmtflags mask = std::ios_base::boolalpha | std::ios_base::dec | std::ios_base::scientific) const
		{
			std::stringstream ss;
			ss << std::setiosflags(mask) << *_value;
			return std::move(ss.str());
		}

		virtual ~TypeTmpl()
		{
			delete _value;
		}
};

template<> std::string TypeTmpl<std::string>::toString(std::ios_base::fmtflags mask) const;



class GenericType
{
	private:
		Type* _type;
	public:
		GenericType(Type* type):
			_type(type)
		{
		}
		GenericType(const GenericType& genericType):
			_type(genericType._type->clone())
		{
		}

		GenericType& operator=(const GenericType& genericType)
		{
			delete _type;
			_type=genericType._type->clone();
			return *this;
		}

		GenericType(GenericType&& genericType):
			_type(genericType._type)
		{
			genericType._type = nullptr;
		}

		GenericType& operator=(GenericType&& genericType)
		{
			delete _type;
			_type=genericType._type;
			genericType._type=nullptr;
			return *this;
		}

		template<class TYPE> static GenericType fromValue(TYPE value);


		//TODO: make those conversion methods test the limits or check the default int/fp type sizes above
		static GenericType fromBoolString(std::string str)
		{
			std::transform(str.begin(), str.end(), str.begin(), (int (*)(int))std::toupper);
			if (str=="TRUE")
			{
				GenericType gt = GenericType(new TypeTmpl<bool>(true));
				return std::move(gt);
			}
			else if (str=="FALSE")
			{
				GenericType gt = GenericType(new TypeTmpl<bool>(false));
				return std::move(gt);
			}
			else
			{
				throw std::string("Error during conversion of '"+str+"' to bool.");
			}
		}

		static GenericType fromInt32String(std::string str)
		{
			try
			{
				GenericType gt = GenericType(new TypeTmpl<int32>(std::stoi(str)));
				return std::move(gt);
			}
			catch (std::invalid_argument ex)
			{
				throw std::string("Invalid argument '"+str+"' during converting to int32.");
			}
			catch (std::out_of_range ex)
			{
				throw std::string("Out-of-range during converting '"+str+"' to int32.");
			}
		}

		static GenericType fromUInt32String(std::string str)
		{
			try
			{
				GenericType gt = GenericType(new TypeTmpl<uint32>(std::stoul(str)));
				return std::move(gt);
			}
			catch (std::invalid_argument ex)
			{
				throw std::string("Invalid argument '"+str+"' during converting to uint32.");
			}
			catch (std::out_of_range ex)
			{
				throw std::string("Out-of-range during converting '"+str+"' to uint32.");
			}
		}

		static GenericType fromFloat32String(std::string str)
		{
			try
			{
				GenericType gt = GenericType(new TypeTmpl<float32>(std::stof(str)));
				return std::move(gt);
			}
			catch (std::invalid_argument ex)
			{
				throw std::string("Invalid argument '"+str+"' during converting to float32.");
			}
			catch (std::out_of_range ex)
			{
				throw std::string("Out-of-range during converting '"+str+"' to float32.");
			}
		}

		static GenericType fromFloat64String(std::string str)
		{
			try
			{
				GenericType gt = GenericType(new TypeTmpl<float64>(std::stod(str)));
				return std::move(gt);
			}
			catch (std::invalid_argument ex)
			{
				throw std::string("Invalid argument '"+str+"' during converting to float64.");
			}
			catch (std::out_of_range ex)
			{
				throw std::string("Out-of-range during converting '"+str+"' to float64.");
			}
		}

		inline std::string toString(std::ios_base::fmtflags mask = std::ios_base::boolalpha | std::ios_base::dec | std::ios_base::scientific) const
		{
			return std::move(_type->toString(mask));
		}

		virtual ~GenericType()
		{
			delete _type;
		}

};


template<class TYPE> GenericType GenericType::fromValue(TYPE value)
{
	GenericType gt = GenericType(new TypeTmpl<TYPE>(value));
	return std::move(gt);
}

}

#endif


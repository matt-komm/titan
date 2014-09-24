#ifndef __TYPES_H__
#define __TYPES_H__

#include <inttypes.h>
#include <string>
#include <sstream>

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

struct FontStyle
{
	enum type {NORMAL,BOLD,ITALIC,BOLDITALIC};
};

class GenericType
{
	private:
		union Data {
			std::string* _str;
			int32* _int;
			float32* _float;
			bool* _bool;
		};
		Data _data;

		enum class DataType {STRING, INT, FLOAT, BOOL};
		DataType _type;

	public:
		GenericType(const char* str):
			_type(DataType::STRING)
		{
			_data._str = new std::string(str);
		}

		GenericType(int32 value):
			_type(DataType::INT)
		{
			_data._int = new int32(value);
		}

		GenericType(float32 value):
			_type(DataType::FLOAT)
		{
			_data._float = new float32(value);
		}

		GenericType(bool boolean):
			_type(DataType::BOOL)
		{
			_data._bool = new bool(boolean);
		}

		static GenericType asString(std::string str)
		{
			return std::move(GenericType(str.c_str()));
		}

		static GenericType asInt(std::string str)
		{
			return std::move(GenericType((int32)std::stoi(str)));
		}

		static GenericType asFloat(std::string str)
		{
			return std::move(GenericType((float32)std::stod(str)));
		}

		static GenericType asBool(std::string str)
		{
			return std::move(GenericType(str=="true"));
		}

		inline bool isString() const
		{
			return _type==DataType::STRING;
		}

		inline bool isInt() const
		{
			return _type==DataType::INT;
		}

		inline bool isFloat() const
		{
			return _type==DataType::FLOAT;
		}

		inline bool isBool() const
		{
			return _type==DataType::BOOL;
		}

		std::string toString() const
		{
			std::stringstream ss;
			switch (_type)
			{
				case DataType::STRING:
				{
					ss << (*_data._str).c_str();
					break;
				}
				case DataType::INT:
				{
					ss << *_data._int;
					break;
				}
				case DataType::FLOAT:
				{
					ss << *_data._float;
					break;
				}
				case DataType::BOOL:
				{
					ss << ((*_data._bool) ? "true" : "false");
					break;
				}

			}

			return std::move(ss.str());
		}

		~GenericType()
		{
			/*
			switch (_type)
			{
				case DataType::STRING:
				{
					delete _data._str;
				}
				case DataType::INT:
				{
					delete _data._int;
				}
				case DataType::FLOAT:
				{
					delete _data._float;
				}
				case DataType::BOOL:
				{
					delete _data._bool;
				}
			}*/
		}

};

}

#endif


#ifndef __GENERICTYPE_H__
#define __GENERICTYPE_H__

#include <string>

#include "titan/core/Types.hpp"
#include "titan/core/Exception.hpp"

namespace titan
{

class Type
{
    public:
        virtual Type* clone() const = 0;
        virtual bool operator==(const Type* type) const= 0;
        virtual bool operator!=(const Type* type) const= 0;
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

        virtual bool operator==(const Type* type) const
        {
            const TypeTmpl<TYPE>* otherType = dynamic_cast<const TypeTmpl<TYPE>*>(type);
            if (!otherType)
            {
                return false;
            }
            return ((*_value)==(*otherType->_value));
        }

        virtual bool operator!=(const Type* type) const
        {
            const TypeTmpl<TYPE>* otherType = dynamic_cast<const TypeTmpl<TYPE>*>(type);
            if (!otherType)
            {
                return true;
            }
            return ((*_value)!=(*otherType->_value));
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

        inline bool operator==(const GenericType& genericType) const
        {
            return (*_type)==genericType._type;
        }

        inline bool operator!=(const GenericType& genericType) const
        {
            return (*_type)!=genericType._type;
        }

        template<class TYPE> static GenericType fromValue(TYPE value);


        //TODO: make those conversion methods test the limits or check the default int/fp type sizes above

        static GenericType fromString(const std::string& str)
        {
            return std::move(GenericType(new TypeTmpl<std::string>(str)));
        }

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
                titan_throw("ConversionError","Error during conversion of '"+str+"' to bool.");
            }
        }

        static GenericType fromInt32String(const std::string& str)
        {
            try
            {
                GenericType gt = GenericType(new TypeTmpl<int32>(std::stoi(str)));
                return std::move(gt);
            }
            catch (std::invalid_argument& ex)
            {
                titan_throw("ConversionError","Invalid argument '"+str+"' during converting to int32.");
            }
            catch (std::out_of_range& ex)
            {
                titan_throw("OutOfRangeError","Out-of-range during converting '"+str+"' to int32.");
            }
        }

        static GenericType fromUInt32String(const std::string& str)
        {
            try
            {
                GenericType gt = GenericType(new TypeTmpl<uint32>(std::stoul(str)));
                return std::move(gt);
            }
            catch (std::invalid_argument& ex)
            {
                titan_throw("ConversionError","Invalid argument '"+str+"' during converting to uint32.");
            }
            catch (std::out_of_range& ex)
            {
                titan_throw("OutOfRangeError","Out-of-range during converting '"+str+"' to uint32.");
            }
        }

        static GenericType fromFloat32String(const std::string& str)
        {
            try
            {
                GenericType gt = GenericType(new TypeTmpl<float32>(std::stof(str)));
                return std::move(gt);
            }
            catch (std::invalid_argument& ex)
            {
                titan_throw("ConversionError","Invalid argument '"+str+"' during converting to float32.");
            }
            catch (std::out_of_range& ex)
            {
                titan_throw("OutOfRangeError","Out-of-range during converting '"+str+"' to float32.");
            }
        }

        static GenericType fromFloat64String(const std::string& str)
        {
            try
            {
                GenericType gt = GenericType(new TypeTmpl<float64>(std::stod(str)));
                return std::move(gt);
            }
            catch (std::invalid_argument& ex)
            {
                titan_throw("ConversionError","Invalid argument '"+str+"' during converting to float64.");
            }
            catch (std::out_of_range& ex)
            {
                titan_throw("OutOfRangeError","Out-of-range during converting '"+str+"' to float64.");
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

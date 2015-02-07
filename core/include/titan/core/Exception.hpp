#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "titan/core/Types.hpp"
#include "titan/core/StreamInterface.hpp"

#include <string>
#include <sstream>

namespace titan
{

class Exception:
    public StreamInterface
{
    protected:
        const std::string _type;
        const std::string _file;
        const std::string _function;
        const uint32 _lno;
        std::stringstream _msg;

        Exception(std::string type, std::string file, std::string function, uint32 lno):
            _type(type),_file(file),_function(function),_lno(lno)
        {
        }
    public:
        Exception(const Exception& e):
            _type(e._type),_file(e._file),_function(e._function),_lno(e._lno)
        {
            _msg<<e._msg.str();
        }

        Exception(Exception&& e):
            _type(std::move(e._type)),_file(std::move(e._file)),_function(std::move(e._function)),_lno(e._lno)
        {
            _msg<<e._msg.str();
        }

        inline const std::string& type() const
        {
            return _type;
        }

        inline const std::string& file() const
        {
            return _file;
        }

        inline const std::string& function() const
        {
            return _function;
        }

        inline uint32 lno() const
        {
            return _lno;
        }

        inline std::string msg() const
        {
            return std::move(_msg.str());
        }

        template<class... ARGS>
        static Exception create(std::string type, std::string file, std::string function, uint32 lno, const ARGS&... args)
        {
            Exception e(type,file,function,lno);
            e.add(args...);
            return std::move(e);
        }

        template<class FIRST, class... ARGS> void add(const FIRST& f, const ARGS&... args)
        {
            _msg<<f;
            add(args...);
        }

        void add()
        {
        }

        virtual std::string more() const
        {
            std::stringstream ss;
            ss<<_type<<" in "<<_file<<"@"<<_lno<<" within "<<_function<<": "<<_msg.str();
            return std::move(ss.str());
        }

        virtual std::string toString() const
        {
            std::stringstream ss;
            ss<<_type<<": "<<_msg.str();
            return std::move(ss.str());
        }
};

}

#define titan_throw(TYPE,...) \
    throw titan::Exception::create(TYPE,__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)

#endif

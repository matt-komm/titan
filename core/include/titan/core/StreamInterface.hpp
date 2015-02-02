#ifndef __STREAMINTERFACE_H__
#define __STREAMINTERFACE_H__

#include <string>
#include <ostream>

namespace titan
{

class StreamInterface
{
    protected:
    public:
        //Printable();
        
        virtual std::string toString() const = 0;

        virtual ~StreamInterface()
        {
        }
};

std::ostream& operator<<(std::ostream& stream, const StreamInterface& streamInterface);


}
#endif


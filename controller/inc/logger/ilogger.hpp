#ifndef ILOGGER_HPP
#define ILOGGER_HPP 

#include <string>
namespace core 
{
struct ILogger 
{
    virtual ~ILogger(){};
    virtual void write(const std::string& log) = 0;
};
}
#endif // ! ILOGGER_HPP

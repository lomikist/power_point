#ifndef OSLOGGER_HPP
#define OSLOGGER_HPP 
#include "ilogger.hpp"
#include <memory>
#include <ostream>

namespace core
{
class OsLogger : public ILogger
{
public:
    OsLogger(std::ostream* stream);
    ~OsLogger();
    void write(const std::string& log) override;
private:
    std::ostream* _device = nullptr;
};
}
#endif // !OSLOGGER_HPP

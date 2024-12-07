#ifndef LOGGER_HPP 
#define LOGGER_HPP 

#include "ilogger.hpp"
#include <memory>
#include <vector>

namespace core
{
class Logger
{
public: 
    ~Logger();
    static Logger& get_instance();
    void add_logger(std::shared_ptr<ILogger> new_one);
    void notify_loggers(const std::string& message);
private:
    Logger();
    std::vector<std::shared_ptr<ILogger>> _loggers;
};
}

#endif // !LOGGER_HPP 

#include "logger.hpp"

using namespace core; 

Logger::Logger()
{};

Logger::~Logger()
{};

Logger& Logger::get_instance()
{
    static Logger _instance;
    return _instance;
};

void Logger::add_logger(std::shared_ptr<ILogger> new_logger)
{
    _loggers.push_back(new_logger);
};

void Logger::notify_loggers(const std::string& message)
{
    for (auto&& logger : _loggers)
    {
        logger->write(message);
    }
};

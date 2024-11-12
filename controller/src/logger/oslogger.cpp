#include "oslogger.hpp"
#include <iostream>
#include <memory>
#include <ostream>

using namespace core;


OsLogger::OsLogger(std::ostream* stream)
{
    _device = stream;
};

OsLogger::~OsLogger()
{
};

void OsLogger::write(const std::string& log)
{
    *_device << log;
    _device->flush();
}

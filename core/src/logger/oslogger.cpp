#include "oslogger.hpp"
#include <iostream>
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
    *_device << log << "\n";
    _device->flush();
}

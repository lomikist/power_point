#include "guilogger.hpp"
#include "qtextbrowser.h"

using namespace core;

GuiLogger::GuiLogger(QTextBrowser* device)
{
    _device = device;
};

GuiLogger::~GuiLogger()
{
}

void GuiLogger::write(const std::string& message)
{
    _device->append(QString::fromStdString(message));
}


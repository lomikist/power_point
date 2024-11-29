#ifndef GUILOGGER_HPP
#define GUILOGGER_HPP 
#include "ilogger.hpp"
#include "qtextbrowser.h"
#include <string>

namespace core
{
class GuiLogger : public ILogger 
{
public:
    GuiLogger(QTextBrowser* device);
    ~GuiLogger();
    void write(const std::string& message) override;
private:
    QTextBrowser* _device = nullptr; 
};
}
#endif // !GUILOGGER_HPP

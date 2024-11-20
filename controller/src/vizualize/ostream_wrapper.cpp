#include "ostream_wrapper.hpp"

using namespace core;

OstreamWrapper::OstreamWrapper(std::ostream& device) : _device(&device)
{
}

void OstreamWrapper::draw_line(int x, int y, int w, int h) 
{
    /*_device->drawLine(x, y, w, h);*/
};
void OstreamWrapper::draw_elipse(int x, int y, int w, int h)
{
    /*_device->drawEllipse(x, y, w, h);*/
};
void OstreamWrapper::draw_rect(int x, int y, int w, int h) 
{
    /*_device->drawRect(x, y, w, h);*/
};
void OstreamWrapper::draw_text(int x, int y, int w, int h, const std::string& content) 
{
    /*_device->drawText(x, y, QString::fromStdString(content));*/
};

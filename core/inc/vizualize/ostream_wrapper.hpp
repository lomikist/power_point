#ifndef OSTREAM_WRAPPER_HPP
#define OSTREAM_WRAPPER_HPP

#include "icanvas.hpp"
#include <iostream>
namespace core 
{
class OstreamWrapper : public ICanvas
{
public:
    ~OstreamWrapper() = default;
    OstreamWrapper(std::ostream& device);
    virtual void draw_line(int x, int y, int w, int h) override;
    virtual void draw_elipse(int x, int y, int w, int h) override;
    virtual void draw_rect(int x, int y, int w, int h) override;
    virtual void draw_text(int x, int y, int w, int h, const std::string& content) override;
private:
    std::ostream* _device;
};
}


#endif// !OSTREAM_WRAPPER_HPP

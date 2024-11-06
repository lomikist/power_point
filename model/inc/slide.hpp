#ifndef SLIDE_HPP 
#define SLIDE_HPP 
#include <memory>
#include <ostream>
#include <vector>
#include <string>
#include "shape.hpp"
#include <iostream>
namespace model
{

using Content = std::vector<std::shared_ptr<AShape>>;

class Slide 
{
public:
    Slide(const std::string& title);
    void                add_shape(std::shared_ptr<AShape> shape);
    void                remove_shape(int index); 
    int                 get_id() const;
    const Content&      get_content() const; 
    Content&            get_content(); 
    const std::string&  get_title() const;
private:
    inline static int s_id = 0;
    Content     _shapes;
    std::string _title;
    int         _id;
};
}

#endif //  SLIDE_HPP!

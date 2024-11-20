#ifndef SLIDE_HPP 
#define SLIDE_HPP 
#include <memory>
#include <ostream>
#include <vector>
#include <string>
#include "item.hpp"
#include <iostream>
namespace model
{

using Content = std::vector<std::shared_ptr<Item>>;

class Slide 
{
public:
    Slide(const std::string& title);
    void                add_item(std::shared_ptr<Item> shape);
    void                remove_item(size_t index); 
    int                 get_id();
    const Content&      get_content() const; 
    Content&            get_content(); 
    const std::string&  get_title() const;
    std::string&  get_title();
private:
    inline static int s_id = 0;
    Content     _shapes;
    std::string _title;
    int         _id;
};
}

#endif //  SLIDE_HPP!

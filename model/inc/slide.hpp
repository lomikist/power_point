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

using Element = std::shared_ptr<Item>;
using Content = std::vector<Element>;

class Slide 
{
public:
    Slide(const std::string& title);
    void                add_item(Element shape);
    void                remove_item(int id); 
    int                 get_id() const;
    const Content&      get_content() const; 
    void                set_content(const Content& content); 
    const std::string&  get_title() const;
    void                set_title(const std::string& title);
    Element             get_item(int id);
private:
    inline static int s_id = 0;
    Content     _shapes;
    std::string _title;
    int         _id;
};
}

#endif //  SLIDE_HPP!

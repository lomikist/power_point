#ifndef ADD_SLIDE_SEM_HPP
#define ADD_SLIDE_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class AddSlideSem : public ASemAn
{
public:
    AddSlideSem();
    Atributes get_args(); 

private:
    Atributes _args;

    void add_title(const std::string& opt, const std::string& args);
    void add_index(const std::string& opt, const std::string& args);
};
}
#endif // ADD_SLIDE_SEM_HPP  

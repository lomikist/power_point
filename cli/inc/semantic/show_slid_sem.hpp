#ifndef SHOW_SLIDE_SEM_HPP
#define SHOW_SLIDE_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class ShowSlideSem : public ASemAn
{
public:
    ShowSlideSem();

    Atributes get_args();
private:
    Atributes _args;
    void add_index(const std::string& opt, const std::string& arg);
    void add_type(const std::string& opt, const std::string& arg);
    void add_path(const std::string& opt, const std::string& arg);
};
}
#endif // SHOW_SLIDE_SEM_HPP

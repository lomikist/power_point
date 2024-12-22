#ifndef SHOW_SLIDE_SEM_HPP
#define SHOW_SLIDE_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class ShowSlideSem : public ASemAn
{
protected:
    ShowSlideSem();

    std::unordered_map<std::string, Var_SID> _args;
private:
    void add_index(const std::string& opt, const std::string& arg);
    void add_type(const std::string& opt, const std::string& arg);
    void add_path(const std::string& opt, const std::string& arg);
};
}
#endif // SHOW_SLIDE_SEM_HPP

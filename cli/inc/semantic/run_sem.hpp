#ifndef RUN_SEM_HPP
#define RUN_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class RunSem : public ASemAn
{
public:
    RunSem();

    Atributes get_args();
private:
    Atributes _args;
    void add_path(const std::string& opt, const std::string& path); 
};
}
#endif // RUN_SEM_HPP

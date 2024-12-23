#ifndef RENDO_SEM_HPP
#define RENDO_SEM_HPP

#include "asem_an.hpp"

namespace cli
{
class RendoSem : public ASemAn
{
public:
    RendoSem();

    Atributes get_args();
private:
    Atributes _args;
    void add_count(const std::string& opt, const std::string& arg);
};
}
#endif // RENDO_SEM_HPP

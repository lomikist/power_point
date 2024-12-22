#ifndef ASEM_AN_HPP
#define ASEM_AN_HPP
#include "type.hpp"
#include <string>

namespace cli
{
class ASemAn
{
public:
    virtual void process_args(const cli::RawArguments& com_info);
protected:
    std::map<std::string, F_vs> _options;
};
}
#endif //ASEM_AN_HPP

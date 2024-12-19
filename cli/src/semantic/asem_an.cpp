#include "asem_an.hpp"

using namespace cli;

void ASemAn::process_args(const cli::RawArguments& arguments)
{
    for (auto&& opt : arguments)
    {
        if (_options.find(opt.first) != _options.end())
        {
            _options[opt.first](opt.first, opt.second);
        } else 
        {
            throw std::runtime_error("CLI: OPTION NOT FOUND:" + opt.first);
        }
    }
};


#include "run_sem.hpp"

using namespace cli;

RunSem::RunSem()
{
    _options["-p"] = [this](const std::string& opt, const std::string& arg) { add_path(opt, arg); };
}

void RunSem::add_path(const std::string& opt, const std::string& path)
{
    _args[opt] = path; 
};


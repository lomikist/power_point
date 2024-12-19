#include "exit_com.hpp"

using namespace cli;

void ExitCom::execute()
{
    std::exit(0);   
};

ExitCom::ExitCom(const CommandInfo& com)
{
    /*process_args(com._arguments);*/
}

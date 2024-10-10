#ifndef RUN_COM_HPP
#define RUN_COM_HPP
#include "icommand.hpp"
#include <functional>
#include <map>
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>

namespace cli 
{
class RunCom : public ICommand 
{ 
public:
    RunCom();
    ~RunCom() = default;
    void execute() override;
    void process_args(const std::vector<std::string>&) override;
    void add_path(const std::string& path); 
    std::unordered_map<std::string, std::variant<std::string, int, double>> _args;
private:
    void register_options();
    std::map<std::string, std::function<void(const std::string& str)>> _options;
};
}
#endif // !RUN_COM_HPP


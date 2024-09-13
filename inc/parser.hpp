#ifndef PARSER_HPP
#define PARSER_HPP

#include <istream>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
struct Indexes;
class Parser
{
public:
    Parser() {
        _subcommands["add"] = {"-slide", "-shape"};
        _subcommands["remove"] = {"-slide", "-shape"}; 
        _subcommands["swap"] = {"-slide", "-shape"};
        _subcommands["show"] =  {"-slide", "-shape"};
        _subcommands["help"] = {};
        _subcommands["exit"] = {};
        
        _options["-slide"] = {"-n", "-r"};
        _options["-shape"] = {"rect", "circle", "-r"};
        
        _arguments["rect"] = {"-x", "-y", "-h", "-w"};
        _arguments["circle"] = {"-x", "-y", "-r"};
    };
    Parser(Parser &&) = default;
    Parser(const Parser &) = default;
    Parser &operator=(Parser &&) = default;
    Parser &operator=(const Parser &) = default;
    ~Parser() = default;
    void start();
    void tokenize(std::string);
private:
    std::string _current;
    std::vector<std::string> _pipe_tokens;
    std::vector<std::string> _tokens;
    std::vector<std::string> _commands = {"add", "remove", "help", "swap", "show"};
    std::unordered_map<std::string, std::vector<std::string>> _subcommands;
    std::unordered_map<std::string, std::vector<std::string>> _options;
    std::unordered_map<std::string, std::vector<std::string>> _arguments;

    std::vector<std::string> split(const std::string& user_input, char ch); 
    void subcommand_check(const std::string &token, Indexes& indexes);
    void option_check(const std::string &token, Indexes& indexes);
    void argument_check(const std::string &token, Indexes& indexes);
};

#endif

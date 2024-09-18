#ifndef PARSER_HPP
#define PARSER_HPP
#include <istream>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "add_slide_command.hpp"
#include "command_factory.hpp"
namespace CLI {
class Parser
{
public:
    Parser();
    Parser(Parser &&) = default;
    Parser(const Parser &) = default;
    Parser &operator=(Parser &&) = default;
    Parser &operator=(const Parser &) = default;
    ~Parser() = default;
    void start(std::string);
    std::vector<std::string> _pipe_tokens;
    std::vector<std::string> _tokens;
private:
    std::vector<std::string> split(const std::string& input, char ch);
    CommandFactory _command_creator;
};
}
#endif

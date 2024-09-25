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
#include "observer.hpp"
#include "subject.hpp"

namespace cli
{
class Parser : public Subject
{
public:
    Parser();
    Parser(Parser &&) = default;
    Parser(const Parser &) = default;
    Parser &operator=(Parser &&) = default;
    Parser &operator=(const Parser &) = default;
    ~Parser() = default;
    // observer
    void add_observer(std::shared_ptr<cli::Observer>) override;
    void remove_observer(std::shared_ptr<cli::Observer>) override;
    void notify_observers(const std::shared_ptr<cli::Command>& ) override;
    //
    void start(std::string);
    std::vector<std::string> _pipe_tokens;
    std::vector<std::string> _tokens;
private:
    std::vector<std::string> split(const std::string& input, char ch);
    std::vector<std::shared_ptr<Observer>> _observers;
    CommandFactory _command_creator;
};
}
#endif

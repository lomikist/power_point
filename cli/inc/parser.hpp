#ifndef PARSER_HPP
#define PARSER_HPP
#include <iostream>
#include <istream>
#include <memory>
#include <vector>
#include "command_factory.hpp"
#include "icommand.hpp"

namespace cli
{
enum class TokenType
{
    NUMBER,
    SUBCOM,
    WORD,
    ARGUMENT,
    BADTYPE
};

class Parser
{
public:
    Parser();
    ~Parser();
    std::shared_ptr<ICommand>   parse(std::istream& is);
    static int                  str_to_int(const std::string& str);
private:   
    std::vector<TokenType>      tokenize(const std::string& str);
    void                        validate_tokens();
    std::shared_ptr<ICommand>   validate_semantics();
    std::vector<std::string>    split(const std::string& input, char ch);
    TokenType                   get_token_type(const std::string& token);
    std::vector<TokenType>      _tokens;
    std::vector<std::string>    _str_tokens;
    cli::CommandFactory         _command_creator;
};
}
#endif // !PARSER_HPP

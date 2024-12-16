#ifndef PARSER_HPP
#define PARSER_HPP
#include <iostream>
#include <istream>
#include <memory>
#include <unordered_set>
#include "command_factory.hpp"
#include "icommand.hpp"

namespace cli
{
enum TokenType
{
    START,
    WORD,
    SUBCOM,
    OPT,
    NUM,
    MVAL,
    SCON,
    ECON,
    BADTYPE
};

using ValidStates = std::unordered_map<TokenType, std::unordered_set<TokenType>>;

class Parser
{
public:
    Parser();
    ~Parser();
    std::shared_ptr<ICommand>       parse(std::istream& is);
    static int                      str_to_int(const std::string& str);
    static std::vector<std::string> splitString(const std::string& str, char delimiter);
private:   
    class Tokenizer 
    {
        public:
            TokenType   get_token(const std::string& token);
        private:
            bool        start_con_check(const std::string& str); 
            bool        end_con_check(const std::string& str); 
            bool        word_check(const std::string& str); 
            bool        opt_check(const std::string& str); 
            bool        num_check(const std::string& str); 
            bool        mval_check(const std::string& str); 
            bool        subcom_check(const std::string& str);
    };

    void command_init();
    void create_table(); 
    void shape_command(TokenType token, const std::string& raw_token);

    Tokenizer                   _tokenizer;
    CommandFactory              _command_creator;

    ////////////////////
    TokenType                   _current_state = TokenType::START;
    ValidStates                 _valid_states;
    CommandInfo                 _command_info; 
    int                         _token_order = 0; 
    bool                        _content_started = false;
    std::string                 _last_option;
    std::string                 _content;

    void                        reset();
};
}
#endif // !PARSER_HPP

#ifndef ACOMMAND_HPP
#define ACOMMAND_HPP

#include <vector>
#include <string>

class Command
{ 
public:
    ~Command() = default;
    virtual void execute(const std::vector<std::string>&) = 0;
protected:
};

#endif // !ACOMMAND_HPP


#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP
namespace cli 
{
class ICommand 
{ 
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};
}
#endif // !ICOMMAND_HPP


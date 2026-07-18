#include <string>
#include <vector>
#include <set>
#include "commands.hpp"
class CLIValidator
{
private:
    int minArgument = 1;
    std::set<std::string> recognizedCommand = RECOGNIZED_COMMAND;
    std::vector<std::string> args;
    bool minArgumentIsValid();
    bool commandIsRecognized();

public:
    void validate(std::vector<std::string> args, std::string &err, std::string &out);
};
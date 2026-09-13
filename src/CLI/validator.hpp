#include <string>
#include <vector>
#include <set>
#include "commands.hpp"
class CLIValidator
{
private:
    int minArgument = 2;
    std::set<std::string> recognizedCommand = RECOGNIZED_COMMAND;
    std::set<std::string> recognizedObject = RECOGNIZED_OBJECT;
    std::vector<std::string> args;
    std::string command;
    std::string object;
    bool minArgumentIsValid();
    bool commandIsRecognized();
    bool isLedgerTemplate();

public:
    void validate(std::vector<std::string> args, std::string &err, std::string &out);
};
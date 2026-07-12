#include <string>
#include <vector>
#include <set>
class CLIValidator
{
private:
    int minArgument = 1;
    std::set<std::string> RECOGNIZED_COMMAND = {
        "add",
    };
    std::vector<std::string> args;
    bool minArgumentIsValid();
    bool commandIsRecognized();

public:
    void validate(std::vector<std::string> args, std::string &err, std::string &out);
};
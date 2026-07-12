#include <string>
#include "validator.hpp"

class CLIApp
{
public:
    void initCLI();
    bool isRunning = false;
    std::string err;
    std::string out;
    CLIValidator validator = CLIValidator();

private:
    bool checkClose(std::string input);
    void inputHandler(std::string input);
};
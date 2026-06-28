#include <string>

class CLIApp
{
public:
    void initCLI();
    bool isRunning = false;

private:
    bool checkClose(std::string input);
};
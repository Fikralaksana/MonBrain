#include <string>

class CLIApp
{
public:
    void initCLI();
    bool isRunning = false;
    std::string err;
    std::string out;

private:
    bool checkClose(std::string input);
    void inputHandler(std::string input);
};
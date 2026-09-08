#include <iostream>
#include <ctime>
#include <string>
#include "Database/base.h"
#include "migration.hpp"
#include "CLI/cli.hpp"

// Available menu
enum RUN_MODE_ENUM
{
    MIGRATE,
    LEDGER,
    SHELL,
};

RUN_MODE_ENUM getRunMode(std::string textMOde)
{
    std::map<std::string, RUN_MODE_ENUM> const RUN_MODE = {
        {"migrate", RUN_MODE_ENUM::MIGRATE},
        {"shell", RUN_MODE_ENUM::SHELL},
        {"ledger", RUN_MODE_ENUM::LEDGER},
    };
    auto mode = RUN_MODE.find(textMOde);
    if (mode != RUN_MODE.end())
    {
        return mode->second;
    }
    else
    {
        throw 1;
    }
}

/*
This is main executable.
There are two mode which can be controlled by an argument:
1. Running the app.
2. Doing migration.
*/
int main(int argc, char *argv[])
{
    std::cout << "Starting Monbrain";
    pqxx::connection connection = connectToDB();
    RUN_MODE_ENUM mode;

    // Validate that app called by an argument
    if (argc < 1)
    {
        return 1;
    }

    // Validate that app called with correct 1st argument
    try
    {
        mode = getRunMode(std::string(argv[1]));
    }
    catch (int errorCode)
    {
        return errorCode;
    }
    if (mode == RUN_MODE_ENUM::MIGRATE)
    {
        appMigration(connection);
    }
    else if (mode == RUN_MODE_ENUM::SHELL)
    {
        std::cout << "CLI session in started\n";
        CLIApp cli = CLIApp();
        cli.initCLI();
    }
    else if (mode == RUN_MODE_ENUM::LEDGER)
    {
    }
    else
    {
        return 1;
    }

    return 0;
}
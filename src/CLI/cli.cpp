#include "cli.hpp"
#include <readline/readline.h>
#include <iostream>
#include <vector>
#include "utils.h"
#include "commands.hpp"
#include "handlers.hpp"

const std::string EXIT_SIGNAL = "exit";

/**
 * @brief Initialization of commandline behaviour
 *
 * Initialization of commandline behaviour.
 * Starting a loop of listening user input.
 * Exit if the input is `exit` and key combination like interrupt, etc
 *
 * @details
 *  1. Mark isRunning true
 *  2. Starting a loop
 *  3. Ignore nullptr (empty value submitted by a user, should continue to next loop)
 *  4. Check if supplied text is exit signal
 *  5. If yes, exit the loop and Mark isRunning false
 *  6. if not, handle the text input
 *
 * @code
 * CLIApp cli = CLIApp()
 * cli.initCLI();
 */
void CLIApp::initCLI()
{
    // TODO: handle runtime error. This function should not throw any exception.
    // Exception should be catch and the CLI should be marked isRunning false.
    isRunning = true;
    while (isRunning)
    {
        std::string cursor = "$$$: ";
        if (err.size() > 0)
        {
            cursor = err + "\n" + cursor;
        }
        else if (out.size() > 0)
        {
            cursor = out + "\n" + cursor;
        }
        char *line = readline(cursor.c_str());
        err = "";
        if (line == nullptr)
        {
            continue;
        }
        bool isClose = checkClose(std::string(line));
        if (isClose)
        {
            break;
        }
        inputHandler(std::string(line));
    }
    isRunning = false;
}

/**
 * @brief A checker function that check an exit signal from input.
 *
 * @param input A string input to check if the input match with exit signal
 *
 * @return bool true if the text match the signal, false otherwise.
 *
 * @details
 *  1. Compare input with exit signal
 *  2. If match return true
 *  3. If not return false
 *
 * @code
 * bool isClose = checkClose("exit"); // This will return true
 */
bool CLIApp::checkClose(std::string input)
{
    if (input == EXIT_SIGNAL)
    {
        return true;
    }
    return false;
}

/**
 * @brief A handler to process user input
 *
 * @param input User input.
 *
 * TODO: details to be filled when the whole function is done
 * @details
 *  1.
 *
 * @code
 * inputHandler("add hello");
 */
void CLIApp::inputHandler(std::string input)
{
    std::vector<std::string> args = splitText(input);
    CLIHandlers handler = CLIHandlers();
    validator.validate(args, err, out);
    if (!(err == ""))
    {
        return;
    }
    std::string command = args[0];

    // Route handler
    // Add
    if (COMMAND_MAPS[command] == COMMAND::ADD)
    {
        int isError = handler.add(args);
    }
}
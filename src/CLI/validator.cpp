#include "validator.hpp"
#include <iostream>
#include <typeinfo>

/**
 * @brief Validate an input with some rules
 *
 * @param args A vector of string, each item represent a command or argument that need to be validated.
 *
 * @details
 *  1. Validate against minimum arguments.
 *  2. Validate agains 1st agrs (a command) is recognized.
 *
 * @code
 * CLIValidator validator = CLIValidator();
 * validator.validate({"add","ledger",...}, err, out);
 */
void CLIValidator::validate(std::vector<std::string> args, std::string &err, std::string &out)
{
    this->args = args;
    if (!minArgumentIsValid())
    {
        err = "No command!";
        return;
    }

    if (!commandIsRecognized())
    {
        err = "Command not recognized";
        return;
    }

    if (!isLedgerTemplate)
    {
        err = "Payload is in correct";
        return;
    }
}

/**
 * @brief Validate args on minimum args rule.
 *
 * @return bool True if then input pass the check, fail otherwise.
 *
 * @details
 *  1. Get the arguments from object attribute and get the size
 *  2. Compare with minArgument
 *  3. If arguments size less than minimum argument return false
 *  4. Otherwise return true
 *
 * @code
 * CLIValidator validator = CLIValidator();
 * validator.minArgumentIsValid();
 */
bool CLIValidator::minArgumentIsValid()
{
    if (args.size() < minArgument)
    {
        return false;
    }
    return true;
}

/**
 * @brief Validate args is in recognized command list.
 *
 * @return bool True if then input pass the check, fail otherwise.
 *
 * @details
 *  1. Check the 1st argument is in the part of recognized command
 *
 * @code
 * CLIValidator validator = CLIValidator();
 * validator.minArgumentIsValid();
 */
bool CLIValidator::commandIsRecognized()
{
    std::string command = args[0];
    std::string object = args[1];
    if (!(recognizedCommand.contains(command)))
    {
        return false;
    }

    if (!(recognizedObject.contains(object)))
    {
        return false;
    }
    return true;
}
/**
 * @brief Validate the args match with Ledger template.
 *
 * @return bool True if then input pass the check, fail otherwise.
 *
 * @details
 * 1. extract a transaction from arguments
 *   0 -> Command
 *   1 -> Object
 *   2 -> Source account
 *   3 -> Destination account
 *   4 -> Amount
 *   5 -> Description
 * @code
 * CLIValidator validator = CLIValidator();
 * validator.isLedgerTemplate();
 */
bool CLIValidator::isLedgerTemplate()
{
    if (!(args.size() != 6))
    {
        return false;
    }
    if (!(typeid(args[2]) != typeid(std::string)))
    {
        return false;
    }
    if (!(typeid(args[3]) != typeid(std::string)))
    {
        return false;
    }
    try
    {
        std::string amountString = args[4];
        std::stod(amountString);
    }
    catch (std::exception &)
    {
        return false;
    }
    if (!(typeid(args[4]) != typeid(double)))
    {
        return false;
    }
    if (!(typeid(args[5]) != typeid(std::string)))
    {
        return false;
    }
    return true;
}
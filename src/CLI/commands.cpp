#include "commands.hpp"

// map of commands
std::map<std::string, COMMAND> COMMAND_MAPS = {
    {"add", COMMAND::ADD}};
/**
 * @brief convert map of commands into set.
 * This is needed because it was easier to use for validator
 * to check the given string in the set using .contains
 *
 * @return std::set<std::string> A set of recognized command.
 *
 * @details
 *  1. Loop the contents of a map
 *  2. Take the key and put it into the set
 *  3. Return the set
 *
 * @code
 * boolean isExist = RECOGNIZED_COMMAND.contains("xxx");
 */
const std::set<std::string> RECOGNIZED_COMMAND = []()
{
    std::set<std::string> commands;
    for (auto &pair : COMMAND_MAPS)
    {
        commands.insert(pair.first);
    }
    return commands;
}();

// map of objects
std::map<std::string, OBJECT> OBJECT_MAPS = {
    {"ledger", OBJECT::LEDGER}};
/**
 * @brief convert map of objects into set.
 * This is needed because it was easier to use for validator
 * to check the given string in the set using .contains
 *
 * @return std::set<std::string> A set of recognized object.
 *
 * @details
 *  1. Loop the contents of a map
 *  2. Take the key and put it into the set
 *  3. Return the set
 *
 * @code
 * boolean isExist = RECOGNIZED_OBJECT.contains("xxx");
 */
const std::set<std::string> RECOGNIZED_OBJECT = []()
{
    std::set<std::string> objects;
    for (auto &pair : OBJECT_MAPS)
    {
        objects.insert(pair.first);
    }
    return objects;
}();

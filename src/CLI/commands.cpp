#include "commands.hpp"

std::map<std::string, COMMAND> COMMAND_MAPS = {
    {"add", COMMAND::ADD}};
const std::set<std::string> RECOGNIZED_COMMAND = []()
{
    std::set<std::string> commands;
    for (auto &pair : COMMAND_MAPS)
    {
        commands.insert(pair.first);
    }
    return commands;
}();

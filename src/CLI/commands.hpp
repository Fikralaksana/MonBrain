#pragma once
#include <set>
#include <string>
#include <map>
#include <ranges>

enum COMMAND
{
    ADD
};

extern std::map<std::string, COMMAND> COMMAND_MAPS;
extern const std::set<std::string> RECOGNIZED_COMMAND;

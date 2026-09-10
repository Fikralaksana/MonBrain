#pragma once
#include <set>
#include <string>
#include <map>
#include <ranges>

enum class COMMAND
{
    ADD
};

extern std::map<std::string, COMMAND>
    COMMAND_MAPS;
extern const std::set<std::string> RECOGNIZED_COMMAND;

enum class OBJECT
{
    LEDGER
};

extern std::map<std::string, OBJECT>
    OBJECT_MAPS;
extern const std::set<std::string> RECOGNIZED_OBJECT;
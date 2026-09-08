#include "handlers.hpp"
#include "commands.hpp"
#include "Ledger/ledger.h"
#include <chrono>

/**
 * @brief Add entry to selected object
 *
 * @param parameter_name Description of parameter.
 *
 * @return return_type Description of return value.
 *
 * @details
 *  1. set default column width
 *
 * @code
 * std::vector<std::string>  v = {"column1","column2"};
 */
int CLIHandlers::add(std::vector<std::string> &args)
{
    std::string &object = args[1];
    if (RECOGNIZED_OBJECT.contains(object))
    {
        Entry entry1;
        entry1.accountID = args[2];
        entry1.credit = std::stod(args[4]);
        entry1.debit = std::stod(args[5]);
        entry1.description = args[6];
        entry1.groupId = args[7];
        entry1.ID = args[8];
        auto now = std::chrono::system_clock::now();
        entry1.timestamp = std::chrono::system_clock::to_time_t(now);
        ledger.addEntry(entry1);

        return 0;
    }
    else
    {
        return 1;
    }
}

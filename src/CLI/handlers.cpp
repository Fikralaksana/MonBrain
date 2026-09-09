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
        Transaction transaction;
        transaction.ID = args[2];
        transaction.sourceAccount = args[3];
        transaction.destinationAccount = args[4];
        transaction.amount = std::stod(args[5]);
        transaction.description = args[6];
        auto now = std::chrono::system_clock::now();
        transaction.timestamp = std::chrono::system_clock::to_time_t(now);
        ledger.addEntry(transaction);

        return 0;
    }
    else
    {
        return 1;
    }
}

#include "handlers.hpp"
#include "commands.hpp"
#include "../Ledger/ledger.h"
#include <chrono>
#include <uuid/uuid.h>

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
    std::string object = args[1];
    if (!RECOGNIZED_OBJECT.contains(object))
    {
        return 1;
    }
    if (OBJECT_MAPS[object] == OBJECT::LEDGER)
    {
        Transaction transaction;
        uuid_t ID;
        char IDChar[37];
        uuid_generate(ID);
        uuid_unparse(ID, IDChar);
        transaction.ID = std::string(IDChar);
        transaction.sourceAccount = args[2];
        transaction.destinationAccount = args[3];
        transaction.amount = std::stod(args[4]);
        transaction.description = args[5];
        auto now = std::chrono::system_clock::now();
        transaction.timestamp = std::chrono::system_clock::to_time_t(now);
        ledger.addEntry(transaction);
    }
    return 0;
}

#include "utils.h"
#include "ledger.h"

void Ledger::showRecentEntries()
{
    std::string header = composeRow(headers);
    std::cout << "\n"
              << header;
}
void Ledger::addEntry(Transaction transaction)
{
    Entry entry1;
    entry1.groupId = transaction.ID;
    entry1.ID = "";
    entry1.accountID = transaction.sourceAccount;
    entry1.debit = -transaction.amount;
    entry1.credit = transaction.amount;
    entry1.timestamp = transaction.timestamp;
    entry1.description = transaction.description;
    entries.push_back(entry1);

    Entry entry2;
    entry2.groupId = transaction.ID;
    entry2.ID = "";
    entry2.accountID = transaction.sourceAccount;
    entry2.debit = transaction.amount;
    entry2.credit = -transaction.amount;
    entry2.timestamp = transaction.timestamp;
    entry2.description = transaction.description;
    entries.push_back(entry2);
}
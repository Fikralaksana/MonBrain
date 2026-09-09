#include <string>
#include <vector>
#include <iostream>
#include "utils.h"

/**
 * @brief This is an interface object to be used for represent a transaction.
 * This object will be processed into double entry.
 * Use this object for functionality outside the ledger.
 */
struct Transaction
{
    std::string ID;
    time_t timestamp;
    std::string sourceAccount;
    std::string destinationAccount;
    double amount;
    std::string description;
};

/**
 * @brief An entry object to input into the ledger.
 * Use this object if the data should be recorded into the ledger.
 */
struct Entry
{
    std::string ID;
    std::string groupId;
    time_t timestamp;
    std::string accountID;
    double debit;
    double credit;
    std::string description;
};

/**
 * @brief In here this system should be able track new entry.
 * A transaction can be a debit or credit
 *
 * Debit is when the assets increase after transaction.
 * We can say that, any funds that coming in into an account vault debit.
 *
 * Credit is when the assets decrease after transaction.
 * We can say that, any funds that coming out from an account vault is credit.
 */
class Ledger
{
private:
    std::vector<Entry> entries;
    std::vector<std::string> headers = {"ID", "Group ID", "Timestamp", "Account ID", "Debit", "Credit", "Description"};

public:
    void showRecentEntries();
    void addEntry(Transaction transaction);
};
#include <string>
#include <vector>
#include <iostream>
#include "utils.h"
struct Entry {
    std::string ID;
    std::string groupId;
    time_t timestamp;
    std::string accountID;
    double debit;
    double credit;
    std::string description;

};

/*
 * In here this system should be able track new entry.
 * A transaction can be a debit or credit
 *
 * Debit is when the assets increase after transaction. 
 * We can say that, any funds that coming in into an account vault debit.
 *
 * Credit is when the assets decrease after transaction.
 * We can say that, any funds that coming out from an account vault is credit.
*/
class Ledger {
    private:
        std::vector<Entry> entries;
        std::vector<std::string> headers={"ID","Group ID", "Timestamp", "Account ID","Debit","Credit","Description"};
        
        
    public:
        void showRecentEntries();
        void addEntry(Entry entry);

};
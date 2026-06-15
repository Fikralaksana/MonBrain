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

class Ledger {
    private:
        std::vector<Entry> entries;
        std::string headers[7]={"ID","Group ID", "Timestamp", "Account ID","Debit","Credit","Description"};
        
        
    public:
        void showRecentEntries();
        void addEntry(Entry entry);

};
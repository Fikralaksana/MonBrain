#include "utils.h"
#include "ledger.h"
#include "../Database/base.h"


void Ledger::showRecentEntries(){
            connectToDB();
            std::string header = composeRow(headers);
            std::cout<<"\n"<<header;
        }
void Ledger::addEntry(Entry entry){
    entries.push_back(entry);
}
#include "utils.h"
#include "ledger.h"



void Ledger::showRecentEntries(){
            std::string header = composeRow(headers);
            std::cout<<"\n"<<header;
        }
void Ledger::addEntry(Entry entry){
    entries.push_back(entry);
}
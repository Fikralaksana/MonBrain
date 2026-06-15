#include "utils.h"
#include "ledger.h"

void Ledger::showRecentEntries(){
            int columnWidth=20;
            std::cout<<"\n";
            std::string row;
            for (std::string header:headers){
                int remainingSpace = getRemainingSpaceForRenderingColumn(header,columnWidth);
                row += header+std::string(remainingSpace,' ');
            }
            std::cout<<row<<"\n";

        }
void Ledger::addEntry(Entry entry){
    entries.push_back(entry);
}
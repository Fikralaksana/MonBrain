#include <string>
#include <vector>
#include <iostream>
#include "utils.h"
#include "ledger.h"

void Ledger::showRecentEntries(){
            int columnWidth=20;
            std::cout<<"\n";
            for (std::string header:headers){
                int remainingSpace = getRemainingSpaceForRenderingColumn(header,columnWidth);
                std::cout<<header;
                for (int i=0;i<remainingSpace;i++){
                    std::cout<<" ";
                }
            }
            std::cout<<"\n";

        }
void Ledger::addEntry(Entry entry){
    entries.push_back(entry);
}
#include <iostream>
#include <ctime>
#include <string>
#include "Ledger/ledger.h"
#include "Database/base.h"

/*
This is main executable.

*/ 


int main(){
    std::cout << "Starting Monbrain";
    connectToDB();
    Ledger ledger=Ledger();
    ledger.showRecentEntries();

    return 0;
}
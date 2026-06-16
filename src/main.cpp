#include <iostream>
#include <ctime>
#include <string>
#include "Ledger/ledger.h"

/*
This is main executable.

*/ 


int main()
{


    std::cout << "Hello World";
    Ledger ledger=Ledger();
    ledger.showRecentEntries();

    return 0;
}
#include <iostream>
#include <ctime>
#include <string>
#include "Ledger/ledger.h"
#include "Ledger/models.h"
#include "Database/base.h"

/*
This is main executable.
There are two mode which can be controlled by an argument:
1. Running the app.
2. Doing migration.
*/ 


int main(int argc, char* argv[]){
    std::cout << "Starting Monbrain";
    pqxx::connection connection = connectToDB();
    if (argc > 1 && std::string(argv[1]) == "migrate") {
        LedgerModel ledgerModel;
        migrate(connection,ledgerModel);
        return 0;
    }
    Ledger ledger=Ledger();
    ledger.showRecentEntries();

    return 0;
}
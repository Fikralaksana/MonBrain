#include <pqxx/pqxx>
#include "Ledger/models.h"

void appMigration(pqxx::connection& connection){
    // Register internal model here to be migrated
    LedgerModel ledgerModel;


    // migration commited here
    migrate(connection,ledgerModel);
}
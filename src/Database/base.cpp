#include "base.h"
#include <iostream>


/**
 * @brief Make a connection to DB
 * 
 * This function make a connection to DB. 
 * It is also make sure the connection is working correctly.
 * by doing simple SELECT query.
 *
 * @details
 *  1. Establish connection.
 *  2. Start a transaction.
 *  3. Execute selectquery
 *  4. Show the query result via cout.
 *
 * @code
 * connectToDB();
 */
pqxx::connection  connectToDB() {
    std::string databaseUrl= "postgresql://postgres:password@db:5432/postgres";
    pqxx::connection connection = pqxx::connection(databaseUrl);
    pqxx::work tx(connection);
    pqxx::row r = tx.exec("SELECT '\nMonbrain connected to DB\n'").one_row();
    tx.commit();
    std::cout << r[0].as<std::string>() << std::endl;
    return connection;
}

/**
 * @brief Do database migration
 * 
 * This function apply database migration from migration class
 * 
 * @param connection An active database connection.
 * @param migration A class that inherit from BaseMigration.
 * @param rollback A boolean value to apply unaplied migration or rollback applied migration.
 * 
 * @details
 * 1. Get sql script that to be sexecuted base on rollback value.
 * 2. Create transaction.
 * 3. Execute the sql script.
 * 4. Commit the transaction.
 * 5. Catch commit error.
 * 
 * @code
 * // initLedger is migration class that create Ledger when applied.
 * // It also will delete if we use it with rollback true.
 * migrate(connection, initLedger); // will create Ledger table
 * migrate(connection, initLedger, rollback=true); // will delete Ledger Table
 */
void migrate(pqxx::connection& connection,BaseMigration& migration, bool rollback) {
    std::string sql = migration.upgradeSQL;
    if (rollback == true) {
        sql = migration.downgradeSQL;
    }
    pqxx::work tx(connection);
    pqxx::result result = tx.exec(sql);
    tx.commit();
    std::cout << "Migrate successfully run\n";
}
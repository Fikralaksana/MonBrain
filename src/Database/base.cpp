#include "base.h"
#include <iostream>

void connectToDB(){
    std::string databaseUrl= "postgresql://postgres:password@db:5432/postgres";
    pqxx::connection cx = pqxx::connection(databaseUrl);
    pqxx::work tx(cx);
    pqxx::row r = tx.exec("SELECT '\nMonbrain connected to DB\n'").one_row();
    tx.commit();
    std::cout << r[0].as<std::string>() << std::endl;
}

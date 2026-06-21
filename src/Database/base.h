#pragma once
#include <pqxx/pqxx>
#include <vector>
#include <string>

class BaseMigration {
    public:
        std::vector<std::string> dependencies;
        std::string upgradeSQL;
        std::string downgradeSQL;
};

pqxx::connection  connectToDB();
void migrate(pqxx::connection& connection,BaseMigration& migration, bool rollback = false);
#include <iostream>
#include <ctime>
#include <string>
#include "Database/base.h"
#include "migration.hpp"

// Available menu
enum RUN_MODE_ENUM {
    MIGRATE,
    SERVE
};

RUN_MODE_ENUM getRunMode(std::string textMOde) {
    std::map<std::string,RUN_MODE_ENUM> const RUN_MODE = {{"migrate",RUN_MODE_ENUM::MIGRATE},{"serve",RUN_MODE_ENUM::SERVE}};
    auto mode = RUN_MODE.find(textMOde);
    if (mode != RUN_MODE.end()) {
        return mode->second;
    } else {
        throw 1;
    }
}

/*
This is main executable.
There are two mode which can be controlled by an argument:
1. Running the app.
2. Doing migration.
*/ 
int main(int argc, char* argv[]){
    std::cout << "Starting Monbrain";
    pqxx::connection connection = connectToDB();
    RUN_MODE_ENUM mode;

    // Validate that app called by an argumen
    if (argc<1) {
        return 1;
    }

    // Validate that app called with correct 1st argumen
    try {
        mode = getRunMode(std::string(argv[1]));
    } catch (int errorCode) {
        return errorCode;
    }


    switch (mode)
    {
    case RUN_MODE_ENUM::MIGRATE:
        appMigration(connection);
        break;
    case RUN_MODE_ENUM::SERVE:
        std::cout<<"Server Runs\n";
        break;
    default:
        break;
    }

    return 0;
}
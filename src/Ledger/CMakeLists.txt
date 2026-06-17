add_library(Ledger ledger.cpp utils.cpp)


target_link_libraries(Ledger PRIVATE Database pqxx)
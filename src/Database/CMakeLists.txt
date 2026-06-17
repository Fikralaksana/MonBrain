add_library(Database base.cpp)

target_link_libraries(Database PRIVATE pqxx)
add_library(CLI cli.cpp)

target_link_libraries(CLI PRIVATE pqxx)
cmake_minimum_required(VERSION 3.23)
project(monbrain)

# 3rd party depedencies
add_subdirectory(Dependencies/libpqxx-7.10.7 build-pqxx)

# Internal module
add_subdirectory(Database)
add_subdirectory(Ledger)

# Executable entry point
add_executable(monbrain main.cpp)

# Link library into the final compile
target_link_libraries(monbrain PRIVATE Ledger Database pqxx)

cmake_minimum_required(VERSION 3.23)
project(monbrain)

# 3rd party depedencies
# add_subdirectory(Dependencies/libpqxx build-pqxx)
include(FindPkgConfig)
pkg_check_modules(PQXX REQUIRED libpqxx)
pkg_check_modules(READLINE REQUIRED readline)

# Internal module
add_subdirectory(Database)
add_subdirectory(Ledger)
add_subdirectory(CLI)

# Executable entry point
add_executable(monbrain main.cpp)

# Link library into the final compile
target_link_libraries(monbrain PRIVATE Ledger Database CLI  ${PQXX_LIBRARIES} ${READLINE_LIBRARIES})

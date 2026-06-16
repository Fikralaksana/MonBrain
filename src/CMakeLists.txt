cmake_minimum_required(VERSION 3.23)

project(monbrain)

add_subdirectory(Ledger)
add_subdirectory(Database)

add_executable(monbrain)

target_link_libraries(monbrain PRIVATE Ledger Database)


target_sources(monbrain
	PRIVATE main.cpp
)
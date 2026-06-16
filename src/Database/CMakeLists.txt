add_library(Database base.cpp)

add_subdirectory(Deps/libpqxx-7.10.7 build-pqxx)

target_include_directories(Database PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} pqxx)
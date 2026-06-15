add_library(Ledger ledger.cpp utils.cpp)


target_include_directories(Ledger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
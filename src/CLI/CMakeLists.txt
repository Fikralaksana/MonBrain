add_library(CLI cli.cpp utils.cpp validator.cpp commands.cpp handlers.cpp)

target_link_libraries(CLI PRIVATE Ledger ${PQXX_LIBRARIES} ${READLINE_LIBRARIES})
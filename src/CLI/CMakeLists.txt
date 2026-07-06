add_library(CLI cli.cpp utils.cpp)

target_link_libraries(CLI PRIVATE ${PQXX_LIBRARIES} ${READLINE_LIBRARIES})
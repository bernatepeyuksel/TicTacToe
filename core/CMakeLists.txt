
file(GLOB_RECURSE SRCS "*.h" "*.cpp")

target_sources(TicTacToe PRIVATE ${SRCS})

target_include_directories(TicTacToe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

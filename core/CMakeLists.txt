set(children "")
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(child ${children})
if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
    set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${child}/src)
    set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${child}/inc)
    set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${child}/test)

    file(GLOB_RECURSE SRCS "${INC_DIR}/*.h" "${SRC_DIR}/*.cpp")

    target_sources(TicTacToe PRIVATE ${SRCS})

    target_include_directories(TicTacToe PUBLIC ${INC_DIR})

    file(GLOB_RECURSE TEST_SRCS "${TEST_DIR}/*.cpp")

    target_sources(unittests PRIVATE ${TEST_SRCS} ${SRCS})

    target_include_directories(unittests PUBLIC ${INC_DIR})
endif()
endforeach()



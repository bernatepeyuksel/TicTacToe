cmake_minimum_required(VERSION 3.18)

project(TicTacToe LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

add_executable(TicTacToe main.cpp ui/qml.qrc)

target_compile_definitions(TicTacToe
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(TicTacToe
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

include(ExternalProject)
ExternalProject_Add(GoogleTest
  GIT_REPOSITORY    git@github.com:google/googletest.git
  GIT_TAG           release-1.11.0
  DOWNLOAD_DIR      ${CMAKE_BINARY_DIR}
  CMAKE_ARGS        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/google-test
)

include(GoogleTest)

enable_testing()

add_executable(unittests main.test.cpp)

target_compile_definitions(unittests
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

add_dependencies(unittests GoogleTest)

add_subdirectory(core)

set(GTEST_ROOT ${CMAKE_BINARY_DIR}/google-test)

find_package(GTest REQUIRED)   

target_link_libraries(
        unittests
        PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
        GTest::Main
    )

    add_test(
        NAME unittests 
        COMMAND unittests
    )    
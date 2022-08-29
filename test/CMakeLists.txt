cmake_minimum_required(VERSION 3.23)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})


add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(TEST_SOURCE_FILES TestsFixture.cpp runAllTests.cpp TestMyApp.cpp TestMyApp.h)
add_executable(runUnitTesting ${TEST_SOURCE_FILES})
target_link_libraries(runUnitTesting gtest gtest_main ${wxWidgets_LIBRARIES} core)



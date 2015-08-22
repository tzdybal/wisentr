cmake_minimum_required(VERSION 2.8)

add_executable(TestRunner main.cpp)
target_link_libraries(TestRunner boost_unit_test_framework)
set_property(TARGET TestRunner PROPERTY CXX_STANDARD 11)

add_test(UnitTests TestRunner)

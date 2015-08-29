cmake_minimum_required(VERSION 2.8)

add_executable(TestRunner 
	main.cpp 
	utils.h utils.cpp
)
target_link_libraries(TestRunner files boost_system boost_filesystem boost_unit_test_framework)
set_property(TARGET TestRunner PROPERTY CXX_STANDARD 11)

add_test(UnitTests TestRunner)

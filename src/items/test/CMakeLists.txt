add_executable(items_tests items_tests.cpp)
target_include_directories(items_tests PUBLIC "./")
target_link_libraries(items_tests PRIVATE items Catch2::Catch2WithMain)

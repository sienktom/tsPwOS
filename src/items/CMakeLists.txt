add_library(items STATIC items.cpp)
target_include_directories(items PUBLIC "./")

add_subdirectory(test)

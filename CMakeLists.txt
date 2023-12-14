cmake_minimum_required(VERSION 3.20)

project(tsPwOS)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(Catch2)

# add_subdirectory(cmake)
# add_subdirectory(extern)
add_subdirectory(src)
# add_subdirectory(test)
# add_subdirectory(doc)

cmake_minimum_required(VERSION 3.11.0)
project(DailyCodingProblem VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("-- Compiling with MSVC")
    add_compile_options(-W4)
    string(REGEX REPLACE "/W3" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message("-- Compiling with Clang")
    add_compile_options(
            -Wall
            -Wextra
            -Werror
            -Wdouble-promotion
            -fno-common
            -Wno-sign-compare
            -Wno-sign-conversion)
else ()
    message("-- Compiling with GCC")
    add_compile_options(
            -Wall
            -Wextra
            -Werror
            -Wdouble-promotion
            -fno-common
            -Wno-sign-compare
            -Wno-sign-conversion)
endif ()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
include(FetchContent)
include(GoogleTest)
enable_testing()

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main)

FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    set(gtest_force_shared_crt
            ON
            CACHE BOOL "" FORCE)
    option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
    option(INSTALL_GTEST "Enable installation of googletest." OFF)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif ()

include_directories(problems/include)
include_directories(include)

file(GLOB_RECURSE src_files "src/*.cpp" "src/*.hpp")

file(GLOB_RECURSE problem_files "problems/*.cpp" "problems/*.hpp")

file(GLOB_RECURSE include_files "include/*.cpp" "include/*.hpp")

# Copy Needed TXT Files to build dir
file(
        COPY ${CMAKE_CURRENT_SOURCE_DIR}/problems/include/problems_081_090/Problem_082.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME} ${src_files} ${problem_files} ${include_files})
target_link_libraries(${PROJECT_NAME} PUBLIC gtest_main)

gtest_discover_tests(${PROJECT_NAME})

target_clangformat_setup(${PROJECT_NAME})

add_custom_target(
        clangtidy
        COMMAND clang-tidy -p ./build --fix-notes --fix-errors ./src/*
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running Clang Tidy...")

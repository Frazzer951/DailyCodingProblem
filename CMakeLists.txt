cmake_minimum_required(VERSION 3.11.0)
project(DailyCodingProblem VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
include(FetchContent)
#set(CMAKE_CXX_CLANG_TIDY clang-tidy -fix)
enable_testing()

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

include_directories(problems)
include_directories(include)

file(GLOB src_files
     "src/*.cpp"
     "src/*.hpp"
)

file(GLOB problem_files
     "problems/*.cpp"
     "problems/*.hpp"
)

file(GLOB include_files
     "include/*.cpp"
     "include/*.hpp"
)

# Copy Needed TXT Files to build dir
file(COPY
    ${CMAKE_CURRENT_SOURCE_DIR}/problems/Problem_082.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(${PROJECT_NAME} ${src_files} ${problem_files} ${include_files} )
target_link_libraries(${PROJECT_NAME} gtest_main)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

target_clangformat_setup(${PROJECT_NAME})
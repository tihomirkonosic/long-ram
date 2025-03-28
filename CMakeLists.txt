cmake_minimum_required(VERSION 3.11)

project(long-ram VERSION 1.0.0
  LANGUAGES CXX
  DESCRIPTION "Mapping application for ultra-long reads")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include(FetchContent)
include(GNUInstallDirs)

find_package(spdlog 1.15.1 QUIET)
if (NOT spdlog_FOUND)
  FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.15.1)

  FetchContent_GetProperties(spdlog)
  if (NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    add_subdirectory(
      ${spdlog_SOURCE_DIR}
      ${spdlog_BINARY_DIR}
      EXCLUDE_FROM_ALL)
  endif ()
endif ()

add_library(long-ram
  src/graph.cpp)

target_include_directories(long-ram PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)

target_link_libraries(long-ram PUBLIC
  spdlog::spdlog_header_only)

add_executable(long-ram-exe
  src/main.cpp
)

target_link_libraries(long-ram-exe
  long-ram)

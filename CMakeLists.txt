cmake_minimum_required (VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)

project(systems-game-engine
  LANGUAGES CXX
  VERSION 0.1.0
)
if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type provided, default to RELEASE.")
  set(CMAKE_BUILD_TYPE "RELEASE")
endif ()

option(SYS_SERVER_TESTS "Whether to build tests." ON)
option(SYS_SERVER_EXAMPLES "Whether to build examples." OFF)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v4.1.1
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

if (SYS_SERVER_TESTS OR ${CMAKE_BUILD_TYPE} STREQUAL "PROFILE")
  enable_testing()
  add_subdirectory(tests)
endif()

if (SYS_SERVER_EXAMPLES)
  add_subdirectory(examples)
endif()

cmake_minimum_required(VERSION 3.19)

if(DEFINED ENV${GITHUB_RUN_NUMBER})
  set(PATCH_NUM $ENV(GITHUB_RUN_NUMBER))
else()
  set(PATCH_NUM 0)
endif()

project(otuscpp
  LANGUAGES CXX
  VERSION 0.0.${PATCH_NUM}
)

configure_file("resources/version.h.in" "version.h")
include_directories(${CMAKE_BINARY_DIR})

include(dependencies/dependencies.cmake)

add_subdirectory(src)

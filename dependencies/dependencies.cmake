 
# Third-party dependencies setup

message(STATUS "Checking third-party dependencies...")

set(DEPENDENCIES_DIR "${CMAKE_SOURCE_DIR}/dependencies")

#--- gtest ---------------------------------------------
set(GTEST_VERSION "1.10.x")
include(dependencies/gtest.cmake)

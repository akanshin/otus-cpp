 
# Third-party dependencies setup

message(STATUS "Checking third-party dependencies...")

set(DEPENDENCIES_DIR "${CMAKE_SOURCE_DIR}/thirdparty")

#--- gtest ---------------------------------------------
set(GTEST_VERSION "1.11.0")
include(thirdparty/gtest.cmake)

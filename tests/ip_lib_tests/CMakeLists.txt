project(ip_lib_tests)

include_directories(
  "${CMAKE_SOURCE_DIR}/src/ip_lib"
)

set(IP_LIB_TESTS_HEADERS
  "precompiled.h"
)

set(IP_LIB_TESTS_SOURCES
  "ipf_ip_tests.cpp"
)

add_executable(ip_lib_tests ${IP_LIB_TESTS_HEADERS} ${IP_LIB_TESTS_SOURCES})

target_precompile_headers(ip_lib_tests PRIVATE "precompiled.h")

target_link_libraries(ip_lib_tests ip_lib gtest_main)

install(TARGETS ip_lib_tests RUNTIME DESTINATION bin)

add_test(ip_lib_tests "${CMAKE_BINARY_DIR}/bin/ip_lib_tests")

project(ip_filter_tests)

include_directories(
  "${CMAKE_SOURCE_DIR}/src/ip_filter"
)

set(IP_FILTER_TESTS_HEADERS
  "precompiled.h"
)

set(IP_FILTER_TESTS_SOURCES
  "ipf_ip_tests.cpp"
)

add_executable(ip_filter_tests ${IP_FILTER_TESTS_HEADERS} ${IP_FILTER_TESTS_SOURCES})

target_precompile_headers(ip_filter_tests PRIVATE "precompiled.h")

target_link_libraries(ip_filter_tests ip_filter gtest_main)

install(TARGETS ip_filter_tests RUNTIME DESTINATION bin)

add_test(ip_filter_tests "${CMAKE_BINARY_DIR}/bin/ip_filter_tests")

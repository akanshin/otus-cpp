project(greetinglib_tests)

include_directories(
  "${CMAKE_SOURCE_DIR}/src/greetinglib"
)

set(GREETINGLIB_TESTS_HEADERS
  "precompiled.h"
)

set(GREETINGLIB_TESTS_SOURCES
  "otus_greeting_tests.cpp"
)

add_executable(greetinglib_tests ${GREETINGLIB_TESTS_HEADERS} ${GREETINGLIB_TESTS_SOURCES})

target_precompile_headers(greetinglib_tests PRIVATE "precompiled.h")

target_link_libraries(greetinglib_tests greetinglib gtest_main)

install(TARGETS greetinglib_tests RUNTIME DESTINATION bin)

add_test(greetinglib_tests "${CMAKE_BINARY_DIR}/bin/greetinglib_tests")

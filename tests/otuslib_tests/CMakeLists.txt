project(otuslib_tests)

include_directories(
  "${CMAKE_SOURCE_DIR}/src/otuslib"
)

set(OTUS_LIB_TESTS_HEADERS
  "precompiled.h"
)

set(OTUS_LIB_TESTS_SOURCES
  "otus_greeting_tests.cpp"
  "main.cpp"
)

add_executable(otuslib_tests ${OTUS_LIB_TESTS_HEADERS} ${OTUS_LIB_TESTS_SOURCES})

target_precompile_headers(otuslib_tests PRIVATE "precompiled.h")

target_link_libraries(otuslib_tests otuslib CONAN_PKG::gtest)

install(TARGETS otuslib_tests RUNTIME DESTINATION bin)

add_test(otuslib_tests "${CMAKE_BINARY_DIR}/bin/otuslib_tests")

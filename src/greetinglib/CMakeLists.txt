project(greetinglib)

add_definitions(-DOTUS_EXPORT)

include_directories(
  #TODO: include third-party dependencies
)

set(GREETINGLIB_HEADERS
  "otus_exports.h"
  "otus_greeting.h"
  "precompiled.h"
)

set(GREETINGLIB_SOURCES
  "otus_greeting.cpp"
)

add_library(greetinglib SHARED ${GREETINGLIB_HEADERS} ${GREETINGLIB_SOURCES})

target_precompile_headers(greetinglib PRIVATE "precompiled.h")

if(UNIX)
  if(NOT APPLE)
    target_link_libraries(greetinglib PRIVATE pthread rt)
  endif(NOT APPLE)
endif(UNIX)

install(TARGETS greetinglib RUNTIME DESTINATION bin)

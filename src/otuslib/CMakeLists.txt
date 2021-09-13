project(otuslib)

add_definitions(-DOTUS_EXPORT)

include_directories(
  #TODO: include third-party dependencies
)

set(OTUS_LIB_HEADERS
  "otus_exports.h"
  "otus_greeting.h"
  "otus_precompiled.h"
)

set(OTUS_LIB_SOURCES
  "otus_greeting.cpp"
)

add_library(otuslib SHARED ${OTUS_LIB_HEADERS} ${OTUS_LIB_SOURCES})

target_precompile_headers(otuslib PRIVATE "otus_precompiled.h")

if(UNIX)
  if(NOT APPLE)
    target_link_libraries(otuslib PRIVATE pthread rt)
  endif(NOT APPLE)
endif(UNIX)

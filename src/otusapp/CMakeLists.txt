project(otusapp)

include_directories(
  "../otuslib"
)

set(OTUS_APP_HEADERS
  "precompiled.h"
)

set(OTUS_APP_SOURCES
  "main.cpp"
)

add_executable(otusapp ${OTUS_APP_HEADERS} ${OTUS_APP_SOURCES})

target_precompile_headers(otusapp PRIVATE "precompiled.h")

target_link_libraries(otusapp otuslib)

install(TARGETS otusapp RUNTIME DESTINATION bin)

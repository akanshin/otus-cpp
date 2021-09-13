project(otusapp)

include_directories(
  "../otuslib"
)

set(OTUS_APP_HEADERS
  "otusapp_precompiled.h"
)

set(OTUS_APP_SOURCES
  "main.cpp"
)

add_executable(otusapp ${OTUS_APP_HEADERS} ${OTUS_APP_SOURCES})

target_precompile_headers(otusapp PRIVATE "otusapp_precompiled.h")

target_link_libraries(otusapp otuslib)

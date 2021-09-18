project(greetingapp)

include_directories(
  "../greetinglib"
)

set(GREETINGAPP_HEADERS
  "precompiled.h"
)

set(GREETINGAPP_SOURCES
  "main.cpp"
)

add_executable(greetingapp ${GREETINGAPP_HEADERS} ${GREETINGAPP_SOURCES})

target_precompile_headers(greetingapp PRIVATE "precompiled.h")

target_link_libraries(greetingapp greetinglib)

install(TARGETS greetingapp RUNTIME DESTINATION bin)

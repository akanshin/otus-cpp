project(ip_filter)

include_directories(
  "../ip_lib"
)

set(IP_FILTER_HEADERS
  "precompiled.h"
)

set(IP_FILTER_SOURCES
  "main.cpp"
)

add_executable(ip_filter ${IP_FILTER_HEADERS} ${IP_FILTER_SOURCES})

target_precompile_headers(ip_filter PRIVATE "precompiled.h")

target_link_libraries(ip_filter ip_lib)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

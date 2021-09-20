project(ip_filter)

add_definitions(-DOTUS_EXPORT)

include_directories(
  #TODO: include third-party dependencies
)

set(IP_FILTER_HEADERS
  "ipf_exports.h"
  "ipf_ip.h"
  "precompiled.h"
)

set(IP_FILTER_SOURCES
  "ipf_ip.cpp"
)

add_library(ip_filter SHARED ${IP_FILTER_HEADERS} ${IP_FILTER_SOURCES})

target_precompile_headers(ip_filter PRIVATE "precompiled.h")

if(UNIX)
  if(NOT APPLE)
    target_link_libraries(ip_filter pthread rt)
  endif(NOT APPLE)
endif(UNIX)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

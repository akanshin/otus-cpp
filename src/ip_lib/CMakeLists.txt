project(ip_lib)

add_definitions(-DOTUS_EXPORT)

include_directories(
  #TODO: include third-party dependencies
)

set(IP_LIB_HEADERS
  "ipf_exports.h"
  "ipf_ip.h"
  "precompiled.h"
)

set(IP_LIB_SOURCES
  "ipf_ip.cpp"
)

add_library(ip_lib SHARED ${IP_LIB_HEADERS} ${IP_LIB_SOURCES})

target_precompile_headers(ip_lib PRIVATE "precompiled.h")

if(UNIX)
  if(NOT APPLE)
    target_link_libraries(ip_lib pthread rt)
  endif(NOT APPLE)
endif(UNIX)

install(TARGETS ip_lib RUNTIME DESTINATION bin)

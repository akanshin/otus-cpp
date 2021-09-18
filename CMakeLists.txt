cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

if(DEFINED OTUSCPP_BUILD_VERSION)
  set(VERSION_NUM ${OTUSCPP_BUILD_VERSION})
else()
  set(VERSION_NUM 0.0.0)
endif()

project(otuscpp
  LANGUAGES CXX
  VERSION ${VERSION_NUM}
)

configure_file("resources/version.h.in" "version.h")
include_directories(${CMAKE_BINARY_DIR})

add_subdirectory(src)

option(BUILD_TESTS "Build tests" OFF)

#if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
#endif()

if(UNIX)
  if (APPLE)
    set(CPACK_GENERATOR "ZIP")
  else() #linux
    set(CPACK_GENERATOR "DEB;TGZ")
  endif()
elseif(MSVC)
set(CPACK_GENERATOR "ZIP")
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT djkanshin@gmail.com)

include(CPack)

cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

if(DEFINED ENV${GITHUB_RUN_NUMBER})
  set(PATCH_NUM $ENV{GITHUB_RUN_NUMBER})
else()
  set(PATCH_NUM 0)
endif()

project(otuscpp
  LANGUAGES CXX
  VERSION 0.0.${PATCH_NUM}
)

configure_file("resources/version.h.in" "version.h")
include_directories(${CMAKE_BINARY_DIR})

include(${PROJECT_SOURCE_DIR}/thirdparty/conan.cmake)
conan_cmake_run(
  CONANFILE thirdparty/dependencies.txt
  BASIC_SETUP
  CMAKE_TARGETS
  BUILD missing
  SETTINGS compiler.libcxx=libstdc++${CMAKE_CXX_STANDARD}
  SETTINGS compiler.cppstd=${CMAKE_CXX_STANDARD}
  SETTINGS compiler.version=${CMAKE_CXX_COMPILER_VERSION}
)

add_subdirectory(src)

option(BUILD_TESTS "Build tests" OFF)

#if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
#endif()

if(UNIX)
  if (APPLE)
    set(CPACK_GENERATOR "DMG")
    install(CODE "include(BundleUtilities)
      fixup_bundle(\"${CMAKE_INSTALL_PREFIX}/${APP_NAME}.app\" \"\" \"${CMAKE_BINARY_DIR}\")")
    set(CPACK_GENERATOR "DragNDrop")
  else() #linux
    set(CPACK_GENERATOR "DEB;TGZ")
  endif()
elseif(MSVC)
  set(CPACK_GENERATOR "WIX")
endif()

set(CPACK_GENERATOR "${CPACK_GENERATOR};ZIP")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT djkanshin@gmail.com)

include(CPack)

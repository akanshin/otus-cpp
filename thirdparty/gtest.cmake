message(STATUS "Checking GoogleTest V${GTEST_VERSION}")

# set(GTEST_DOWNLOAD_URL "https://github.com/google/googletest/archive/refs/tags/release-${GTEST_VERSION}.zip")
# set(GTEST_DOWNLOAD_PATH "${DEPENDENCIES_DIR}/files/googletest/v${GTEST_VERSION}.zip")
# set(GTEST_UNPACK_PATH "${DEPENDENCIES_DIR}/files/googletest/v${GTEST_VERSION}")
# set(GTEST_PATH "${GTEST_UNPACK_PATH}/googletest-release-${GTEST_VERSION}")

# if (NOT EXISTS "${GTEST_DOWNLOAD_PATH}")
#   message(STATUS "Downloading GoogleTest V${GTEST_VERSION}")
#   file(DOWNLOAD
#     "${GTEST_DOWNLOAD_URL}"
#     "${GTEST_DOWNLOAD_PATH}"
#     SHOW_PROGRESS
#     TLS_VERIFY ON)
# endif ()

# if (NOT EXISTS ${GTEST_PATH})
#   file(ARCHIVE_EXTRACT
#     INPUT "${GTEST_DOWNLOAD_PATH}"
#     DESTINATION "${GTEST_UNPACK_PATH}")
# endif ()

# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
# set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

# add_subdirectory(${GTEST_PATH})

# set_target_properties(gtest gtest_main
#   PROPERTIES
#   CXX_STANDARD 17
# )
############################################################################################
# include(ExternalProject)
# ExternalProject_Add(googletest
#     URL https://github.com/google/googletest/archive/refs/tags/release-${GTEST_VERSION}.zip
#     URL_HASH SHA1=9ffb7b5923f4a8fcdabf2f42c6540cce299f44c0
#     INSTALL_COMMAND ""
# )

# ExternalProject_Get_Property(googletest binary_dir)
# add_library(gtest UNKNOWN IMPORTED)
# add_library(gtest_main UNKNOWN IMPORTED)
# set_target_properties(gtest PROPERTIES
#     IMPORTED_LOCATION ${binary_dir}/libgtest.a
# )
# set_target_properties(gtest_main PROPERTIES
#     IMPORTED_LOCATION ${binary_dir}/libgtest_main.a
# )
# add_dependencies(gtest googletest)
# add_dependencies(gtest_main googletest)

# set(GTEST_INCLUDE "${CMAKE_BINARY_DIR}/googletest-prefix/src/googletest/googletest/include")
################################################################################################
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-${GTEST_VERSION}.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

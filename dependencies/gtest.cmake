message(STATUS "Checking GoogleTest V${GTEST_VERSION}")

set(GTEST_DOWNLOAD_URL "https://github.com/google/googletest/archive/v${GTEST_VERSION}.zip")
set(GTEST_DOWNLOAD_PATH "${DEPENDENCIES_DIR}/files/googletest/v${GTEST_VERSION}.zip")
set(GTEST_UNPACK_PATH "${DEPENDENCIES_DIR}/files/googletest/v${GTEST_VERSION}")
set(GTEST_PATH "${GTEST_UNPACK_PATH}/googletest-${GTEST_VERSION}/googletest")

if (NOT EXISTS "${GTEST_DOWNLOAD_PATH}")
  message(STATUS "Downloading GoogleTest V${GTEST_VERSION}")
  file(DOWNLOAD
    "${GTEST_DOWNLOAD_URL}"
    "${GTEST_DOWNLOAD_PATH}"
    SHOW_PROGRESS
    TLS_VERIFY ON)
endif ()

if (NOT EXISTS ${GTEST_PATH})
  file(ARCHIVE_EXTRACT
    INPUT "${GTEST_DOWNLOAD_PATH}"
    DESTINATION "${GTEST_UNPACK_PATH}")
endif ()

set(gtest_force_shared_crt ON)

add_subdirectory(${GTEST_PATH})

set_target_properties(gtest gtest_main PROPERTIES CXX_STANDARD 17)

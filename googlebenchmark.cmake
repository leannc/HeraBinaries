
set(SOURCE_DIR ${DEPENDENCY_DIR}/benchmark)

ExternalProject_Add(
    googlebenchmark_project
    SOURCE_DIR ${SOURCE_DIR}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${Binary_DIR}/benchmark/${LIB_TYPE_DIR_NAME} -DGOOGLETEST_PATH=${DEPENDENCY_DIR}/googletest
    INSTALL_DIR ${Binary_DIR}/benchmark/${LIB_TYPE_DIR_NAME}
)
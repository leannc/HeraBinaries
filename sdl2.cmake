


#${DEPENDENCY_DIR}/googletest 就是googletest源码所在文件夹
set(SOURCE_DIR ${DEPENDENCY_DIR}/SDL)


#直接一个命令，全部搞定，因为它默认就是会开启install的，所以这里我们只需要设置install的prefix就可以了
ExternalProject_Add(
    sdl_project
    SOURCE_DIR ${SOURCE_DIR}
    CMAKE_ARGS  -DCMAKE_INSTALL_PREFIX=${Binary_DIR}/SDL2/${LIB_TYPE_DIR_NAME}
                -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
    INSTALL_DIR ${Binary_DIR}/SDL2/${LIB_TYPE_DIR_NAME}
)


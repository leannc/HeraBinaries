


#${DEPENDENCY_DIR}/googletest 就是googletest源码所在文件夹
set(SOURCE_DIR ${DEPENDENCY_DIR}/googletest)


#直接一个命令，全部搞定，因为它默认就是会开启install的，所以这里我们只需要设置install的prefix就可以了
ExternalProject_Add(
    googletest_project
    SOURCE_DIR ${SOURCE_DIR}
    CMAKE_ARGS  -DCMAKE_INSTALL_PREFIX=${Binary_DIR}/googletest/${LIB_TYPE_DIR_NAME}
                -Dgtest_force_shared_crt=ON 
    INSTALL_DIR ${Binary_DIR}/googletest/${LIB_TYPE_DIR_NAME}
)


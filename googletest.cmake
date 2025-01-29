
#${DEPENDENCY_DIR}/googletest 就是googletest源码所在文件夹
set(SOURCE_DIR ${DEPENDENCY_DIR}/googletest)

#${Binary_DIR}/googletest/${LIB_TYPE_DIR_NAME}就是install的文件夹
set(CMAKE_INSTALL_PREFIX ${Binary_DIR}/googletest/${LIB_TYPE_DIR_NAME})

#设置在build的时候，会自动install，上面已经设置了install路径
set(INSTALL_GTEST ON CACHE BOOL "Enable installation of googletest" FORCE)

#加载googletest，中间文件放在${CMAKE_BINARY_DIR}/googletest中
add_subdirectory(${SOURCE_DIR} ${CMAKE_BINARY_DIR}/googletest)
cmake_minimum_required(VERSION 3.26)
include(ExternalProject)
project(HeraBinary)

set(CMAKE_CXX_STANDARD 20)

#这个是源码目录，把imgui, spdlog等库的源码放在这个路径里面，这个cmake会自动安装和部署到HeraBinaries里面。
set(DEPENDENCY_DIR "${WORKSPACE_DIR}/Dependencies")

include(imgui.cmake)
include(spdlog.cmake)
include(googletest.cmake)
include(googlebenchmark.cmake)
include(sdl2.cmake)



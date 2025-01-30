
set(prject "imgui")

set(SOURCE_DIR "${DEPENDENCY_DIR}/imgui")

message("source dir is : "${SOURCE_DIR})
file(GLOB IMGUI_SOURCE_FILES
    "${SOURCE_DIR}/imgui.cpp"
    "${SOURCE_DIR}/imgui_demo.cpp"
    "${SOURCE_DIR}/imgui_draw.cpp"
    "${SOURCE_DIR}/imgui_widgets.cpp"
    "${SOURCE_DIR}/imgui_tables.cpp"
)

file(GLOB IMGUI_IMPL_OPENGL3_SOURCE_FILES
    "${SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
    "${SOURCE_DIR}/backends/imgui_impl_sdl2.cpp"
)

file(GLOB_RECURSE IMGUI_HEADER_FILES
    "${SOURCE_DIR}/imconfig.h"
    "${SOURCE_DIR}/imgui.h"
    "${SOURCE_DIR}/imgui_internal.h"
    "${SOURCE_DIR}/imstb_rectpack.h"
    "${SOURCE_DIR}/imstb_textedit.h"
    "${SOURCE_DIR}/imstb_truetype.h"
    "${SOURCE_DIR}/backends/imgui_impl_opengl3.h"
    "${SOURCE_DIR}/backends/imgui_impl_sdl2.h"
)

add_library(${prject}  STATIC
 ${IMGUI_SOURCE_FILES} ${IMGUI_IMPL_OPENGL3_SOURCE_FILES}
 
 )

 target_include_directories(${prject}  
    PRIVATE src/HeraGui
    PRIVATE  ${SOURCE_DIR}
    PRIVATE  ${SOURCE_DIR}/backends
    PRIVATE  ${Binary_DIR}/SDL2/${LIB_TYPE_DIR_NAME}/include/SDL2
)



install(TARGETS ${prject} 
    ARCHIVE DESTINATION ${Binary_DIR}/imgui/${LIB_TYPE_DIR_NAME}
)


install(FILES ${IMGUI_HEADER_FILES}
    DESTINATION ${Binary_DIR}/imgui/include
)
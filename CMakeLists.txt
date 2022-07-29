set(APP_NAME ultralight-opengl-skeleton)
project(${APP_NAME} C CXX)

cmake_minimum_required(VERSION 3.16.0)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE
      "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options("/std:c++latest")



include(cmake/App.cmake)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)



set(SOURCES "src/app.h"
    "src/app.cpp"
    "src/web_tile.h"
    "src/web_tile.cpp"
    "src/window.h"
    "src/window.cpp"
    "src/gl_texture_surface.h"
    "src/gl_texture_surface.cpp"
    "src/main.cpp"
    "src/overlay_ui.h"
    "src/overlay_ui.cpp"
    "src/show_datatype.h"
    "src/show_datatype.cpp"
    "src/renderer.h"
    "src/renderer.cpp"
    "src/util.h"
    "src/util.cpp"
    "src/camera.h"
    "src/camera.cpp"
    "src/type_trait.h"
    "src/vendor/stb_image.h"
    "src/texture.h"
    "src/file.h"
    "src/file.cpp"
    "src/log.h"
    "src/log.cpp"
    "src/opengl_window.h"
    "src/opengl_window.cpp"
    "src/texture.cpp"
    "src/ultralight/keycodes.h"
    "src/ultralight/js_utils.h"
    "src/ultralight/js_event.h"
    "${GLAD_SOURCES}")

add_app("${SOURCES}" "${GLAD_SOURCES}")

set_target_properties(${APP_NAME} PROPERTIES LINK_FLAGS /SUBSYSTEM:CONSOLE)

target_link_libraries(${APP_NAME} PRIVATE glfw)
target_link_libraries(${APP_NAME} PRIVATE glad::glad)
target_link_libraries(${APP_NAME} PRIVATE glm::glm)
target_link_libraries(${APP_NAME} PRIVATE spdlog::spdlog)


file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets/" DESTINATION ${CMAKE_BINARY_DIR}/assets/
    PATTERN "inspector" EXCLUDE
)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets/" DESTINATION ${CMAKE_SOURCE_DIR}/build/assets/
    PATTERN "inspector" EXCLUDE
)
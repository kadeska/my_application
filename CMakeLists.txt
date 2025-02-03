cmake_minimum_required(VERSION 3.19)
project(my_application LANGUAGES CXX)

# Set the Boost root directory
set(BOOST_ROOT "F:/boost/boost_1_87_0")
set(Boost_INCLUDE_DIR "F:/boost/boost_1_87_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/boost")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/libs")

# Manually specify GLEW and GLFW paths as fallback
set(GLEW_INCLUDE_DIRS "/usr/include/GL")
set(GLEW_LIBRARIES "/usr/lib/x86_64-linux-gnu/libGLEW.so")
set(GLFW_INCLUDE_DIRS "/usr/include/GLFW")
set(GLFW_LIBRARIES "/usr/lib/x86_64-linux-gnu/libglfw.so")

# Find packages
find_package(Qt6 6.5 REQUIRED COMPONENTS Core OpenGL Gui Widgets)
find_package(Boost REQUIRED COMPONENTS system)

# Qt standard setup
qt_standard_project_setup()

# Collect source files
set(SOURCE_FILES
    main.cpp
    mainwindow.cpp
    settings_window.cpp
    glWindow/glWindowCore/openglwindow.cpp
    glWindow/glWindowCore/shader.cpp
    glWindow/glWindowCore/texture.cpp
    glWindow/glWindowCore/controls.cpp
    game/core/gamecore.cpp
)

# Collect header files
set(HEADER_FILES
    mainwindow.hpp
    settings_window.hpp
    helper.hpp
    glWindow/glWindowCore/openglwindow.hpp
    glWindow/glWindowCore/shader.hpp
    glWindow/glWindowCore/texture.hpp
    glWindow/glWindowCore/controls.hpp
    game/core/gamecore.hpp
)

# Collect UI files
set(UI_FILES
    ui/mainwindow.ui
    ui/settings_window.ui
)

# Add the executable
qt_add_executable(my_application
    WIN32 MACOSX_BUNDLE
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${UI_FILES}
    game/core/gameclock.hpp game/core/gameclock.cpp
    game/entity/myentity.hpp game/entity/myentity.cpp
    game/entity/player.hpp game/entity/player.cpp
    glWindow/gl/entity/entitybase.hpp glWindow/gl/entity/entitybase.cpp
    glWindow/gl/model/basemodel.hpp glWindow/gl/model/basemodel.cpp
    glWindow/glWindowCore/windowmanager.hpp glWindow/glWindowCore/windowmanager.cpp
    glWindow/glWindowCore/renderer.hpp glWindow/glWindowCore/renderer.cpp
    game/inventory/item.hpp game/inventory/item.cpp
    game/inventory/inventory.hpp game/inventory/inventory.cpp
)

# Include and link libraries
target_include_directories(my_application PRIVATE
    glWindow/glWindowCore
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(my_application
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::OpenGL
        ${GLEW_LIBRARIES}
        ${GLFW_LIBRARIES}
        Boost::system
)

# Copy shader and texture files to the build directory
configure_file(glWindow/gl/shaders/SimpleVertexShader.vertexshader ${CMAKE_BINARY_DIR}/SimpleVertexShader.vertexshader COPYONLY)
configure_file(glWindow/gl/shaders/SimpleFragmentShader.fragmentshader ${CMAKE_BINARY_DIR}/SimpleFragmentShader.fragmentshader COPYONLY)
configure_file(glWindow/gl/uvtemplate.DDS ${CMAKE_BINARY_DIR}/uvtemplate.DDS COPYONLY)

# Install rules for shaders and textures
install(FILES
    glWindow/gl/shaders/SimpleVertexShader.vertexshader
    glWindow/gl/shaders/SimpleFragmentShader.fragmentshader
    glWindow/gl/uvtemplate.DDS
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install the executable
include(GNUInstallDirs)
install(TARGETS my_application
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Deployment script
qt_generate_deploy_app_script(
    TARGET my_application
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

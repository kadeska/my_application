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

# Add the executable
qt_add_executable(my_application
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.hpp
    mainwindow.ui
    settings_window.hpp settings_window.cpp settings_window.ui
    openglwindow.hpp openglwindow.cpp
    shader.hpp shader.cpp
    SimpleVertexShader.vertexshader
    SimpleFragmentShader.fragmentshader
    helper.hpp
)

# Fallback for GLEW if not found
if(NOT GLEW_FOUND)
    message(WARNING "GLEW not found automatically. Using manually specified paths.")
    include_directories(${GLEW_INCLUDE_DIRS})
    target_link_libraries(my_application PRIVATE ${GLEW_LIBRARIES})
else()
    target_link_libraries(my_application PRIVATE GLEW::GLEW)
endif()

# No need for find_package(GLFW when using manual paths
message(STATUS "Using manually specified GLFW include and library paths.")

# Manually include GLFW
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(my_application PRIVATE ${GLFW_LIBRARIES})

# Ensure Boost is properly included
if(Boost_FOUND)
    target_include_directories(my_application PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(my_application PRIVATE Boost::system)
else()
    message(FATAL_ERROR "Boost not found. Make sure Boost is installed and accessible.")
endif()

# Link libraries
target_link_libraries(my_application
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::OpenGL
        Qt::Gui
)

# Copy shader files to the build directory
configure_file(SimpleVertexShader.vertexshader ${CMAKE_BINARY_DIR}/SimpleVertexShader.vertexshader COPYONLY)
configure_file(SimpleFragmentShader.fragmentshader ${CMAKE_BINARY_DIR}/SimpleFragmentShader.fragmentshader COPYONLY)

# Install rules for shader files
install(FILES
    SimpleVertexShader.vertexshader
    SimpleFragmentShader.fragmentshader
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

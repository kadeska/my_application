cmake_minimum_required(VERSION 3.19)
project(my_application LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

# Set the Boost root directory (use BOOST_ROOT consistently for environment variables)
set(BOOST_ROOT "F:/boost/boost_1_87_0")
# set(Boost_DIR "F:\boost\boost_1_87_0")
set(Boost_INCLUDE_DIR "F:/boost/boost_1_87_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/boost")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/libs")

# Find Boost
find_package(Boost REQUIRED COMPONENTS system)



qt_standard_project_setup()

qt_add_executable(my_application
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.hpp
    mainwindow.ui
)

# Include Boost headers and link libraries
if(Boost_FOUND)
    target_include_directories(my_application PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(my_application PRIVATE Boost::system)
else()
    message(FATAL_ERROR "Boost not found. Make sure Boost is installed and accessible.")
endif()


target_link_libraries(my_application
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS my_application
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET my_application
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})



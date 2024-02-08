cmake_minimum_required(VERSION 3.5)

<<<<<<< HEAD
project(bills VERSION 0.1 LANGUAGES CXX)
=======
project(4 VERSION 0.1 LANGUAGES CXX)
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
<<<<<<< HEAD
    qt_add_executable(bills
=======
    qt_add_executable(4
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
<<<<<<< HEAD
#    set_property(TARGET bills APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
=======
#    set_property(TARGET 4 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
<<<<<<< HEAD
        add_library(bills SHARED
=======
        add_library(4 SHARED
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
<<<<<<< HEAD
        add_executable(bills
=======
        add_executable(4
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
            ${PROJECT_SOURCES}
        )
    endif()
endif()

<<<<<<< HEAD
target_link_libraries(bills PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
=======
target_link_libraries(4 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
<<<<<<< HEAD
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.bills)
endif()
set_target_properties(bills PROPERTIES
=======
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.4)
endif()
set_target_properties(4 PROPERTIES
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
<<<<<<< HEAD
install(TARGETS bills
=======
install(TARGETS 4
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
<<<<<<< HEAD
    qt_finalize_executable(bills)
=======
    qt_finalize_executable(4)
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
endif()

